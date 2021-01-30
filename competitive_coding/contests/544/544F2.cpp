#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

map<int, bool> alreadyConnected;
map<int, bool> vis;
int components;
vector<int> color;
vector<vector<int>> g, ans;

int N;

bool compare(int v1, int v2){
    return color[v1] < color[v2];
}

void addEdge(int u, int v, bool bi, vector<vector<int>>& E){
    E[u].push_back(v);
    if(bi)
        E[v].push_back(u);
}


void bfs(int src, int bad, vector<vector<int>> &E, bool print){
    queue<int> q;
    map<int, int> dist;
    map<int, int> parent;

    rep(i, 1, N)
        dist[i] = INT_MAX;

    q.push(src);
    dist[src] = 0;
    parent[src] = src;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(print && parent[node] != node){
            cout<<parent[node]<<" "<<node<<endl;
        }
        color[node] = components;  /// just an id for each node of a given vertex!.

        for(auto neighbor: E[node]){
            if(neighbor!=bad && dist[neighbor] == INT_MAX){
                dist[neighbor] = dist[node]+1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    components++;
    return;
}

int main(){
    int n, m, d;
    cin>>n>>m>>d;
    N = n;
    g = vector<vector<int>>(n+1);
    ans = vector<vector<int>>(n+1);
    int v1, v2;
    while(m--){
        cin>>v1>>v2;
        addEdge(v1, v2, true, g);
        if(v1!=1 && v2!=1)  /// i.e. both not 1
            addEdge(v1, v2, true, ans);
    }

    int deg = g[1].size();
    if(d>deg){
        cout<<"NO";
        return 0;
    }

    components = 0;
    color = vector<int>(n+1, -1);  /// 1 base-indexing.
    if(d == deg){
        /// ques. similar to F1 part, run bfs on node 1.
        cout<<"YES"<<endl;
        bfs(1, -1, g, true);
        return 0;
    }

    rep(node, 2, n){  /// ignoring node 1, while calculating the connected components.
        if(color[node] == -1)
            bfs(node, 1, g, false);
    }
    int cnt = components;

    vector<int> neighbors = g[1];

    if(cnt > d){
        cout<<"NO";
        return 0;
    }

    /// now we have to remove deg-d edges starting from 1 from graph G.
    d -= cnt;
    sort(neighbors.begin(), neighbors.end(), compare);
    for(int i=0; i<neighbors.size(); i++){
        if(i==0 || color[neighbors[i]] != color[neighbors[i-1]]){
            addEdge(1, neighbors[i], true, ans);
        }
        if(color[neighbors[i]] == components-1)
            break;
    }

    // ans.print();

    for(int i=1; i<neighbors.size(); i++){
        if(d==0)
            break;
        if(color[neighbors[i]] == color[neighbors[i-1]]){
            addEdge(1, neighbors[i], true, ans);
            d--;
        }
    }

    // ans.print();

    cout<<"YES"<<endl;
    bfs(1, -1, ans, true);

    return 0;
}

