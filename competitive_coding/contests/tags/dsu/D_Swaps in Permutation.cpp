#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int a[N];
int res[N];
vector<vector<int>> g;
vector<bool> vis(N, false);
set<int> s1, s2;

void dfs(int v){
    if(vis[v]) return;
    s1.insert(v);
    s2.insert(a[v]);
    vis[v] = true;
    for(auto u: g[v]){
        dfs(u);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v;
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    g.resize(n+1);
    for(int i=1; i<=m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        s1.clear();
        s2.clear();
        dfs(i);
        set<int>::iterator it = s1.begin();
        set<int>::reverse_iterator rit = s2.rbegin();
        while(it != s1.end()){
            res[*it] = *rit;
            it++;
            rit++;
        }
    }

    for(int i=1; i<=n; i++){
        if(!res[i]) cout<<a[i]<<" ";
        else cout<<res[i]<<" ";
    }

    return 0;
}