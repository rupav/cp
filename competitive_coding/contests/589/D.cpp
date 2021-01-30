#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)

vector<vector<int>> g;
map<vector<int>, vector<int>> mp;
vector<int> vis;

void dfs(int v){
    vis[v] = true;
    for(auto u: g[v]){
        if(!vis[u]) dfs(u);
    }
}

void solve(int n){
    vis.assign(n, false);
    dfs(0);
    /// should be one component for a complete tripartite graph.
    if(accumulate(vis.begin(), vis.end(), 0) != n) {
        cout<<-1;
        return;
    }
    fr(i, n){
        sort(g[i].begin(), g[i].end());
        mp[g[i]].push_back(i);
    }
    if(mp.size() != 3){
        cout<<-1;
        return;
    }
    vector<int> ans(n);
    int i = 1;
    for(auto it: mp){
        for(auto el: it.second){
            ans[el] = i;
        }
        i++;
    }
    for(auto it: ans) cout<<it<<" ";
    return;
}


int main(){
    int n, m;
    cin>>n>>m;
    int u, v;
    g.resize(n);
    while(m--){
        cin>>u>>v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve(n);
    return 0;
}
