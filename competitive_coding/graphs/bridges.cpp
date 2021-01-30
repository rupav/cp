#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> tin, low;
int timer;

void is_bridge(int a, int b){
    cout<<a<<" "<<b<<endl;
    return;
}

void dfs(int v, int parent = -1){
    vis[v] = true;
    tin[v] = low[v] = timer++;

    for(auto to: g[v]){
        if(to == parent) continue; /// since is an undirected graph
        if(vis[to]){
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(tin[v] < low[to]){
                /// we have found a bridge!
                is_bridge(v, to);
            }
        }
    }
}

void find_bridges(int n){
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    timer = 0;

    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs(i);
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    int x;
    g.resize(n);

    int u, v;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    find_bridges(n);

    return 0;
}
