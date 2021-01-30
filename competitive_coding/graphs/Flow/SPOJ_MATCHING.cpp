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
    int from, to, cap, index, flow;
    Edge(int from, int to, int cap, int index) :
        from(from), to(to), cap(cap), index(index), flow(0) {}
};

struct PushRelabel{
    int N;
    vector<ll> ex;
    vector<int> h, cnt, active;
    vector<vector<Edge>> g;
    queue<int> q;

    PushRelabel(int N) :
        N(N), ex(N), h(N), cnt(2*N), active(N), g(N) {}

    void addEdge(int from, int to, int cap){
        g[from].push_back(Edge(from, to, cap, g[to].size()));
        if(from == to) g[from].back().index++;
        g[to].push_back(Edge(to, from, 0, g[from].size() - 1));
    }

    void enqueue(int v){
        if(!active[v] && ex[v]){
            active[v] = true;
            q.push(v);
        }
    }

    void push(Edge &e){
        int d = int(min(1ll*(e.cap - e.flow), ex[e.from]));
        if(!d || h[e.from] <= h[e.to]) return;
        ex[e.from] -= d;
        ex[e.to] += d;
        e.flow += d;
        g[e.to][e.index].flow -= d;
        enqueue(e.to);
    }

    void gap(int k){
        for(int i=0; i<N; i++){
            if(h[i] < k) continue;
            cnt[h[i]]--;
            h[i] = max(h[i], N + 1);
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
        for(int i=0; i<g[s].size(); i++) tot += g[s][i].flow;
        return tot;
    }

};

void solve(){
    int n, m, u, v, matches;
    cin>>n>>m>>matches;

    int s(0), t(n + m + 1);
    PushRelabel pr(n + m + 2); /// making a flow network for Matching
    fr(i, matches){
        cin>>u>>v;
        pr.addEdge(u, v + n, 1);
    }


    rep(i, 1, n) pr.addEdge(s, i, 1);
    rep(i, n+1, n+m) pr.addEdge(i, t, 1);

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
