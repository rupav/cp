#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> coins;
vector<bool> vis;
vector<int> dp[2]; /// dp[0][i] stores max coins collected including current node, dp[1][i] stores max coins collected excluding current node

void dfs(int v, int p = -1){
    vis[v] = true;
    int sum[2] = {coins[v], 0};

    for(auto u: g[v]){
        if(u == p) continue;
        /// since a tree, no need to check for if already visited or not
        dfs(u, v);
        sum[0] += dp[1][u];
        sum[1] += max(dp[0][u], dp[1][u]);
    }

    dp[0][v] = sum[0];
    dp[1][v] = sum[1];

}

int solve(int n){
    vis.assign(n, false);
    dp[0].assign(n, 0);
    dp[1].assign(n, 0);

    dfs(0);  /// 0th node is assumed to be the root node of the tree

    return max(dp[0][0], dp[1][0]);
}

int main(){
    int n, m;
    cin>>n>>m;
    g.resize(n);
    coins.resize(n);
    int u, v;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0; i<n; i++) cin>>coins[i];

    int sum = solve(n);
    cout<<sum<<endl;

    return 0;
}
