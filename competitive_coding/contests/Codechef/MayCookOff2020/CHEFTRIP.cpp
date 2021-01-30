/// Accepted!
/// https://www.codechef.com/COOK118A/problems/CHEFTRIP
#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;
#define INF INT_MAX

const int N = 1e5 + 5;
vector<int> height(N), par(N), st(N);
vector<pii> euler;
vector<int> a(N);

vector<vector<int>> g;
vector<int> dp[2];  /// furthest increasing and decreasing ancestors of node u

/// Euler tour type - 3
void dfs_euler3(int v, int p, int h = 0){
    par[v] = p;
    height[v] = h;
    euler.push_back({h, v});
    for(auto u: g[v]){
        if(p == u) continue;
        dfs_euler3(u, v, h+1);
        euler.push_back({h, v});
    }
}

/// segment tree to find min. in a range
vector<pii> t;

void build(int n){
    for(int i = n - 1; i > 0; --i)  {
        t[i] = min(t[i<<1], t[i<<1|1]);
    }
}

pii query(int n, int l, int r){
    /// min - [l, r)
    pii mn = {INF, 0};
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1) mn = min(mn, t[l++]);
        if(r&1) mn = min(mn, t[--r]);
    }
    return mn;
}

void dfs(int v, int p, int ht = 0){

    if(a[p] != a[v]){
        dp[(a[p] < a[v])][v] = dp[(a[p] < a[v])][p];
    }

    for(auto u: g[v]){
        if(u == p) continue;
        dfs(u, v, ht + 1);
    }
}


void solve(){
    int n, q, u, v;
    cin>>n>>q;

    euler.clear();
    g.clear();
    g.resize(n + 1);
    fr(i, 2) {
        dp[i].clear();
        dp[i].resize(n + 1);
        iota(dp[i].begin(), dp[i].end(), 0);
    }

    fr(i, n - 1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    rep(i, 1, n) cin>>a[i];

    dfs_euler3(1, 1);

    int m = euler.size();
    t.clear();
    t.resize(2 * m, {0, 0});
    repn(i, m - 1, 0){
        st[euler[i].second] = i;   /// starting point of each node
        t[m + i] = euler[i];
    }
    build(m);

    dfs(1, 1, 0);

    string res = "";

    fr(i, q){
        cin>>u>>v;
        int lca = query(m, min(st[u], st[v]), max(st[u], st[v]) + 1).second;
        bool f = false;

        int x(dp[0][u]), y(dp[0][v]);

        if(height[x] <= height[lca] && height[y] <= height[lca]){
            f = true;
        } else if (height[x] <= height[lca] && height[dp[1][y]] <= height[lca]){
            f = true;
        } else if (height[y] <= height[lca] && height[dp[1][x]] <= height[lca]){
            f = true;
        }

        res += (f) ? "1": "0";
    }

    cout<<res<<endl;
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

