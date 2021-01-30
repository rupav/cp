#include<bits/stdc++.h>
using namespace std;

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

int dx_[] = {0, 1, 0, -1};
int dy_[] = {-1, 0, 1, 0};


/// max flow from Blue to Red, with bidirectional edges, and capacity 1
void solve(){
    int n, m, q, u, v, c;
    char x;
    cin>>n>>m>>q;
    int tot = n * m + 2 * n + 2 * m;
    int s(0), t(tot + 1);

    PushRelabel pr(tot + 2);
    int off = 1;

    fr(left, n){
        cin>>x;
        if(x == 'B'){
            pr.addEdge(s, n * m + off, 1);
        } else {
            pr.addEdge(n * m + off, t, 1);
        }
        int z = left * m + 1;
        pr.addEdge(n * m + off, z, 1);
        pr.addEdge(z, n * m + off, 1);
        off++;
    }

    fr(right, n){
        cin>>x;
        if(x == 'B'){
            pr.addEdge(s, n * m + off, 1);
        } else {
            pr.addEdge(n * m + off, t, 1);
        }
        int z = right * m + m;
        pr.addEdge(n * m + off, z, 1);
        pr.addEdge(z, n * m + off, 1);
        off++;
    }

    fr(up, m){
        cin>>x;
        if(x == 'B'){
            pr.addEdge(s, n * m + off, 1);
        } else {
            pr.addEdge(n * m + off, t, 1);
        }
        int z = 0 * m + up + 1;
        pr.addEdge(n * m + off, z, 1);
        pr.addEdge(z, n * m + off, 1);
        off++;
    }

    fr(down, m){
        cin>>x;
        if(x == 'B'){
            pr.addEdge(s, n * m + off, 1);
        } else {
            pr.addEdge(n * m + off, t, 1);
        }
        int z = (n - 1) * m + down + 1;
        pr.addEdge(n * m + off, z, 1);
        pr.addEdge(z, n * m + off, 1);
        off++;
    }

    auto translate = [&](int x, int y){
        x--;
        return x * m + y;
    };

    auto check = [&](int x, int y){
        if(x < 1 || x > n) return false;
        if(y < 1 || y > m) return false;
        return true;
    };

    rep(i, 1, n){
        rep(j, 1, m){
            int x = translate(i, j);    /// connect to all possible neighbors
            fr(k, 4){
                if(check(i + dx_[k], j + dy_[k])){
                    int y = translate(i + dx_[k], j + dy_[k]);
                    pr.addEdge(x, y, 1);
                }
            }
        }
    }

    cout<<pr.getMaxFlow(s, t)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

