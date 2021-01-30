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
const int N = 2e5 + 5;
vector<vector<int>> g;
bool vis[N];
int n;

bool dfs(int v, vector<int>& path){
    if(vis[v]) return false;
    vis[v] = true;
    bool f = false;
    for(auto u: g[v]){
        f = f || dfs(u, path);
    }
    if(v == n) f = true;
    if(f) path.push_back(v);
    return f;
}

void solve(){
    int x;
    cin>>n;
    g.resize(n + 1);
    fr(i, n-1){
        cin>>x;
        g[x].push_back(i + 2);
    }

    vector<int> path;
    dfs(1, path);

    for(auto rit = path.rbegin(); rit != path.rend(); rit++){
        cout<<(*rit)<<" ";
    }

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

