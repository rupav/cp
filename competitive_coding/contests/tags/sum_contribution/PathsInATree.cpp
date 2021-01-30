/// https://codeforces.com/blog/entry/62690 - 2. sum of Paths in a tree
/// incorrect - I am overcounting

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fr(i, n) for(int i=0; i<n; i++)
const int N = 1e5 +5;
vector<vector<int>> g;
int n;
ll res;

int dfs(int v, int p){
    int cnt = 0;
    int tot = 0;
    for(auto u: g[v]) {
        if(u == p) continue;
        cnt = dfs(u, v);
        tot += cnt;
        res += cnt * 1ll * (n - cnt);   /// considering edge v-u contribution in total res
    }
    return tot + 1;
}

int main() {
    int u, v;
    cin>>n;
    g.resize(n+1);
    fr(i, n-1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    /// root is assumes to be 1
    dfs(1, 1);

    cout<<res;

    return 0;
}
