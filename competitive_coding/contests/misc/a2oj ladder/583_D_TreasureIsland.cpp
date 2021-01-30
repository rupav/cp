/// Push Relabel with gap heurestics. - TLE
#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


struct Edge{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int index) :
        from(from), to(to), cap(cap), flow(0), index(index) {}
};

struct PushRelabel {
    int N;
    vector<vector<Edge>> g;
    vector<ll> ex;
    vector<int> h, cnt, active;
    queue<int> q;

    PushRelabel(int N) :
        N(N), g(N), ex(N), active(N), cnt(2*N), h(N) {}

    void addEdge(int from, int to, int cap){
        /// index of a edge points to the reverse edge's pos. in the list of head of reverse edge's vertex
        g[from].push_back(Edge(from, to, cap, g[to].size()));
        if(from == to) g[from].back().index++;
        g[to].push_back(Edge(to, from, 0, g[from].size()-1));
    }

    void enqueue(int v){
        if(!active[v] && ex[v] > 0) {
            active[v] = true;
            q.push(v);
        }
    }

    void push(Edge &e){
        int d = int(min(ex[e.from], 1ll*(e.cap - e.flow)));
        if(!d || h[e.from] <= h[e.to]) return;
        e.flow += d;
        ex[e.from] -= d;
        ex[e.to] += d;
        g[e.to][e.index].flow -= d;
        enqueue(e.to);
    }

    void gap(int k){
        for(int i=0; i<N; i++){
            if(h[i] < k) continue;
            cnt[h[i]]--;
            h[i] = max(h[i], N);
            cnt[h[i]]++;
            enqueue(i);
        }
    }

    void relabel(int v){
        cnt[h[v]]--;
        h[v] = 2*N;
        for(int i=0; i<g[v].size(); i++){
            if(g[v][i].cap - g[v][i].flow > 0)
                h[v] = min(h[v], h[g[v][i].to] + 1);
        }
        cnt[h[v]]++;
        enqueue(v);
    }

    void discharge(int v){
        for(int i=0; ex[v] && i<g[v].size(); i++) push(g[v][i]);
        if(ex[v]){
            if(cnt[h[v]] == 1) gap(h[v]);
            else relabel(v);
        }
    }

    ll getMaxFlow(int s, int t){
        cnt[0] = N - 1;
        cnt[N] = 1;
        h[s] = N;
        active[s] = active[t] = true;
        for(int i=0; i<g[s].size(); i++){
            ex[s] += g[s][i].cap;
            push(g[s][i]);
        }

        while(!q.empty()){
            int v = q.front();
            q.pop();
            active[v] = false;
            discharge(v);
        }

        ll tot = 0ll;
        for(int i=0; i<g[s].size(); i++){
            tot += g[s][i].flow;
        }

        return tot;
    }

};


/// find min cut, i.e. max flow, which if blocked will block the whole path!
ll solve(){
    int n, m;
    char x;
    cin>>n>>m;
    bool mat[n+1][2*m+1];
    int inf = numeric_limits<int>::max();

    rep(i, 1, n) rep(j, 1, m) {
        cin>>x;
        mat[i][j] = (x == '.');
    }

    PushRelabel pr(2*n*m + 1);
    int s(1), t(2*n*m);

    /// for each each cell generate 2 verices, U in and U out
    rep(i, 1, n){
        for(int j=1; j<2*m; j += 2){
            pr.addEdge((i - 1)*2*m + j, (i - 1)*2*m + j + 1, mat[i][j/2 + 1]);

            /*
            watch((i - 1)*2*m + j);
            watch((i - 1)*2*m + j + 1);

            watch((i - 1)*2*m + j + 1);
            watch((i - 1)*2*m + j + 2);
            watch((i - 1)*2*m + j + 1);
            watch((i - 1 + 1)*2*m + j);
            cout<<endl<<endl;
            */

            if(j + 2 <= 2*m) pr.addEdge((i - 1)*2*m + j + 1, (i - 1)*2*m + j + 2, inf);
            if(i + 1 <= n) pr.addEdge((i - 1)*2*m + j + 1, (i - 1 + 1)*2*m + j, inf);
        }
    }

    pr.addEdge(1, 2, inf);
    pr.addEdge(2*m*n - 1, 2*m*n, inf);

    return pr.getMaxFlow(s, t);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        cout<<solve();
    }

    return 0;
}

