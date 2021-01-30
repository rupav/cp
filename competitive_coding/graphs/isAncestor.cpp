/// checking if a vertex is a ancestor of another in a tree (represented as a graph)
#include<bits/stdc++.h>
using namespace std;

vector<int> entry, ext;  /// for storing time on dfs call

void dfsUtil(int v, int n, vector<vector<int>> &adj, vector<bool> &vis){
    static int time = 0;
    vis[v] = true;
    entry[v] = time;
    time++;
    for(auto u: adj[v]){
        if(!vis[u])
            dfsUtil(u, n, adj, vis);
    }
    ext[v] = time;
    time++;
    return;
}

void dfs(int src, int n, vector<vector<int>> &adj){
    entry.resize(n);
    ext.resize(n);
    vector<bool> vis(n, false);
    /// only one DFS call required from root(src), since its a tree
    dfsUtil(src, n, adj, vis);
}

bool isAncestor(int a, int b){
    /// checks if a is an ancestor of b, given that entry&ext arrays are pre-filled
    return ((entry[a] < entry[b]) && (ext[a] > ext[b]));
}

int main(){
    int n, m;
    cin>>n;
    cin>>m; /// for a tree, m has to be n-1!

    vector<vector<int>> adj(n);
    int x, y;
    while(m--){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, n, adj); /// assuming root is 0
    int q;
    cin>>q;
    while(q--){
        cin>>x>>y;
        cout<<isAncestor(x, y)<<endl;
    }

    return 0;
}
