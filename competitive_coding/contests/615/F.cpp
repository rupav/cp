/// finding diameter of a tree, and all nodes lying on it.

/// In a tree, max. depth point/node from any source node is always either of the two ends of the diameter.
/// Proof: If not, then distance from dest. node to intersection node of dest node and 1st end of dia + dist from intersection to 2nd end
/// would have been greater than dist from 1st end to intersection node of dest node and 1st end of dia + dist from intersection to 2nd end
///, contradicting the fact that distance between 1st end 2nd end is maximum (to be diameter). Hence proved.

/// So to find dia of a tree, find any of the 2 ends from any of the source end, and then again run dfs from this end, to find the diameter!

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> p;

using pii = pair<int, int>;

pii dfs(int v, int par = -1, int dist = 0) {
    p[v] = par;
    pii res = make_pair(dist, v);
    for(auto u : g[v]) {
        if(u == par) continue;
        res = max(res, dfs(u, v, dist + 1));
    }
    return res;
}

int main(){
    int n, u, v;
    cin>>n;
    g.resize(n);
    p.resize(n);

    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    pii da = dfs(0);    /// da.second is 1st end of dia
    pii db = dfs(da.second);    /// db.second is 1st end of dia

    vector<int> dia;
    v = db.second;
    while(v != da.second){
        dia.push_back(v);
        v = p[v];
    }
    dia.push_back(da.second);

    int m = dia.size();

    if(m == n) {
        cout<<m-1<<endl;
        cout<<dia[0] + 1<<" "<<dia[1] + 1<<" "<<dia.back() + 1;
        return 0;
    }

    /// multi-source bfs
    vector<int> d(n, -1); /// distance from the diameter to ith node
    queue<int> q;
    for(auto v: dia) {
        d[v] = 0;
        q.push(v);
    }

    while(!q.empty()) {
        v = q.front();
        q.pop();

        for(auto u: g[v]) {
            if(d[u] == -1){
                d[u] = d[v] + 1;
                q.push(u);
            }
        }

    }

    pii mx = make_pair(d[0], 0);
    for(int v = 0; v < n; v++) {
        mx = max(mx, make_pair(d[v], v));
    }

    cout<<mx.first + m - 1<<endl;
    cout<<dia[0] + 1<<" "<<mx.second + 1<<" "<<dia.back() + 1;

    return 0;
}

