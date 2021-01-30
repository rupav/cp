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
        from(from), to(to), flow(0), cap(cap), index(index) {}
};

struct PushRelabel{
    int N;
    queue<int> q;
    vector<ll> ex;
    vector<vector<Edge>> g;
    vector<int> h, active, cnt;

    PushRelabel(int N) :
        N(N), ex(N), g(N), h(N), active(N), cnt(2*N) {}

    void addEdge(int from, int to, int cap){
        g[from].push_back(Edge(from, to, cap, g[to].size()));
        if(from == to) g[from].back().index++;
        g[to].push_back(Edge(to, from, 0, g[from].size() - 1));
    }

    void enqueue(int v){
        if(!active[v] && ex[v] > 0){
            active[v] = true;
            q.push(v);
        }
    }

    void push(Edge &e){
        int d = int(min(ex[e.from], 1ll*(e.cap - e.flow)));
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
            ex[s] += 1ll*(g[s][i].cap);
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

ll dist(pii p1, pii p2, int fac){
    ll dist = 0ll;
    dist = 1ll*fac*(llabs(p1.first - p2.first) + llabs(p1.second - p2.second));
    return dist;
}

/// TAXI problem
void solve(){
    int n, m, speed, time, x, y;
    cin>>n>>m>>speed>>time;
    const int sz = 200;
    PushRelabel pr(n + m + 2);
    int s(0), t(n + m + 1);
    ll mx = 1ll*speed*1ll*time;    /// max distance

    pii p[n+1];
    pii tx[m+1];

    rep(i, 1, n){
        cin>>x>>y;
        p[i] = {x, y};
        pr.addEdge(s, i, 1);
    }

    rep(i, 1, m){
        cin>>x>>y;
        tx[i] = {x, y};
        pr.addEdge(i + n, t, 1);
    }

    rep(i, 1, n){
        rep(j, 1, m){
            if(dist(p[i], tx[j], sz) <= mx){
                pr.addEdge(i, j + n, 1);
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
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

