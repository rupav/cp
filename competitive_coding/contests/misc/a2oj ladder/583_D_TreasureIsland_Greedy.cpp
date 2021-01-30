/// ACcepted
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

vector<string> g;
vector<vector<bool>> vis;
int n, m;

void dfs(){
    vis[0][0] = true;
    rep(i, 1, n-1) vis[i][0] = (g[i][0] != '#') && vis[i-1][0];
    rep(j, 1, m-1) vis[0][j] = (g[0][j] != '#') && vis[0][j-1];

    rep(i, 1, n-1){
        rep(j, 1, m-1){
            vis[i][j] =  (g[i][j] != '#') && (vis[i-1][j] || vis[i][j-1]);
        }
    }

}

void dfs_greedy(int x, int y, int dir, map<pii, int>& mp){
    if(x == 0 && y == 0) return;
    if(x < 0 || y < 0) return;
    mp[{x, y}]++;
    if(dir){
        /// up
        if(x >= 1 && vis[x-1][y]) dfs_greedy(x-1, y, dir, mp);
        else dfs_greedy(x, y-1, dir, mp);
    } else {
        /// left
        if(y >= 1 && vis[x][y-1]) dfs_greedy(x, y-1, dir, mp);
        else dfs_greedy(x-1, y, dir, mp);
    }
}

int solve(){
    cin>>n>>m;
    g.resize(n);
    vis.resize(n);
    fr(i, n) vis[i].resize(m, false);

    fr(i, n) cin>>g[i];

    dfs();

    if(!vis[n-1][m-1]) return 0;

    /// answer is either 1 or 2
    map<pii, int> mp;
    enum Dir {left, up};

    dfs_greedy(n-1, m-1, Dir::left, mp);
    dfs_greedy(n-1, m-1, Dir::up, mp);

    mp.erase({0, 0});
    mp.erase({n-1, m-1});

    int mx = 1;
    for(auto it: mp) mx = max(it.second, mx);

    return (mx == 1 ? 2 : 1);
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


