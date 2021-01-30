#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> tin, low;
int timer;

set<int> cps; /// cut points

void is_cutpoint(int v){
    cps.insert(v);
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
    if(p == -1 && children > 1){
        is_cutpoint(v);
    }
}

void find_cutpoints(int n){
    timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    cps.clear();

    for(int i=0; i<n; i++){
        if(!vis[i]) dfs(i);
    }

}

int main(){
    return 0;
}
