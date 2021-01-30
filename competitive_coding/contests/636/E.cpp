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
#define INF INT_MAX

const int N = 2e5 + 5;
vector<vector<pii>> g(N);

void Dijkstra(int s, vector<int> &d, vector<int> &p, int n){
    d.assign(n, INF);  /// distances from source s
    p.assign(n, -1);  /// predecessors
    d[s] = 0;
    set<pii> q;
    q.insert(make_pair(d[s], s));
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());

        for(auto neighbor: g[v]){
            /// check for relaxation condition
            if(d[neighbor.first] > d[v] + neighbor.second){
                q.erase(make_pair(d[neighbor.first], neighbor.first));
                d[neighbor.first] = d[v] + neighbor.second;
                q.insert(make_pair(d[neighbor.first], neighbor.first));
                p[neighbor.first] = v;
            }
        }
    }

}

void solve(){
    int n, m, u, v, a[3];
    cin>>n>>m;
    fr(i, 3) cin>>a[i];
    int pc[m];
    fr(i, m) cin>>pc[i];
    sort(pc, pc+m);
    ll pref[m+1] = {0};
    rep(i, 1, m) pref[i] = pref[i-1] + pc[i-1];

    rep(i, 1, n) g[i].clear();

    fr(i, m){
        cin>>u>>v;
        g[u].push_back({v, 1});
        g[v].push_back({u, 1});
    }

    vector<int> d[3];
    vector<int> p[3];
    fr(i, 3) {
        d[i].resize(n+1);
        p[i].resize(n+1);
        Dijkstra(a[i], d[i], p[i], n+1);
    }

    ll ans = numeric_limits<ll>::max();
    ll cost;
    vector<int> z(3);
    ll els;
    rep(i, 1, n){
        cost = 0ll;
        z[0] = 1ll*d[0][i];
        z[1] = 1ll*d[1][i];
        z[2] = 1ll*d[2][i];


        els = 0ll;
        fr(j, 3) els += z[j];
        if(els > m) continue;

        cost = pref[d[1][i]] + pref[els];

        ans = min(cost, ans);
    }

    cout<<ans<<endl;

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

