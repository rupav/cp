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

vector<vector<int>> g;
vector<int> lp; /// longest Directed path starting at i
vector<bool> vis;

void dfs(int v){
    int &mx = lp[v];
    vis[v] = 1;
    for(auto u: g[v]){
        if(!vis[u])
            dfs(u);
        mx = max(lp[u] + 1, mx);
    }
}

void solve(){
    int n, m, u, v;
    cin>>n>>m;
    g.resize(n+1);
    lp.resize(n+1, 1);
    vis.resize(n+1, false);

    fr(i, m){
        cin>>u>>v;
        g[u].push_back(v);
    }

    rep(i, 1, n){
        if(!vis[i]){
            dfs(i);
        }
    }

    cout<<*max_element(lp.begin() + 1, lp.end()) - 1;
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

