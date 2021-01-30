/// in an unweighted graph, find shortest even length path from vertices 'a' and 'b'
#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
vector<vector<int>> adj;
map<pii, vector<pii>> aux;

int special_bfs(int a, int b, int n){
    map<pii, bool> used;
    map<pii, int> d;
    queue<pii> q;
    q.push({a, 0});
    bool parity = false;

    while(!q.empty()){
        pii v = q.front();
        q.pop();
        used[v] = true;
        parity = v.second;
        for(auto u: aux[v]){
            if(!used[u]){
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }

    return d[{b, 0}];  /// shortest even length path from a to b!
}

int main(){
    int n, m; /// no. of edges
    cin>>n;
    adj.resize(n);
    cin>>m;
    int a, b;
    cin>>a>>b;
    int t = m;
    int u, v;
    while(t--){
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        aux[{u, 0}].push_back({v, 1});
        aux[{u, 1}].push_back({v, 0});
        aux[{v, 0}].push_back({u, 1});
        aux[{v, 1}].push_back({u, 0});
    }

    cout<<special_bfs(a, b, n)<<endl;

    return 0;
}
