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
int mod = 1e9+7;

vector<vector<int>> g;
vector<pii> dp;
int n;

void add_self(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}

void mul_self(int &a, int b){
    ll z = (ll) a * b;
    if(z >= mod) z %= mod;
    a = z;
}

void dfs(int v, int p){
    pii &z = dp[v];

    int cnt = 0;
    int prod[2] = {1, 1};
    for(auto u: g[v]){
        if(u == p) continue;
        dfs(u, v);
        cnt++;  /// child count
        mul_self(prod[0], dp[u].second);
        mul_self(prod[1], dp[u].first + dp[u].second);
    }

    z = make_pair(prod[0], prod[1]);
}

void solve(){
    int u, v;
    cin>>n;
    g.resize(n);
    dp.resize(n, {0, 0});
    /// dp[i].first = no. of valid subtrees with vertex i set to black
    /// dp[i].second = no. of valid subtrees with vertex i set to white

    fr(i, n-1){
        cin>>u>>v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto sum = [&](pii z){
        add_self(z.first, z.second);
        return z.first;
    };

    dfs(0, 0);
    cout<<sum(dp[0]);
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
