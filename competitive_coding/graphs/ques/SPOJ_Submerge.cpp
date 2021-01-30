#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)

vector<vector<int>> g;
vector<bool> vis, nodes;
vector<int> tin, low;
int timer;

void is_cutpoint(int v){
    nodes[v] = true;
}

void dfs(int v, int p = -1){
    vis[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;

    for(auto to: g[v]){
        if(to == p) continue;
        if(vis[to]){
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(tin[v] <= low[to] && p != -1){
                is_cutpoint(v);
            }
            children++;
        }
    }

    if(p == -1 && children > 1) is_cutpoint(v);

}

void find_cutpoints(int n){
    vis.assign(n, false);
    nodes.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    timer = 0;

    fr(i, n) if(!vis[i]) dfs(i);
}

int main(){
    while(true){
        int n, m;
        cin>>n>>m;
        if(n == 0 && m == 0) return 0;
        g.clear();
        g.resize(n);
        int u, v;
        while(m--){
            cin>>u>>v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        find_cutpoints(n);
        cout<<accumulate(nodes.begin(), nodes.end(), 0)<<endl;
    }
    return 0;
}
