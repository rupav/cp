#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
typedef pair<int, int> pii;

vector<vector<pii>> g;  /// to represent adjacency list of graph! g[0].push_back({neighbor_vertex_index, binary_weight})

void ZeroOneBFS(int src, int n){
    deque<int> dq;  /// double end queue to do BFS!
    int *dist = new int[n];
    fr(i, n) dist[i] = INT_MAX;
    dist[src] = 0;
    dq.push_back(src);  /// both front and back have this now!
    while(!dq.empty()){
        int node = dq.front();  /// shortest distance element from src till now.
        dq.pop_front();
        /// iterate all over its neighbors
        for (auto it: g[node]) {
            int neighbor = it.first;
            int weight = it.second;
            /// check if relaxed
            if (dist[node] + weight < dist[neighbor]){
                /// update the dist
                dist[neighbor] = dist[node] + weight;
                /// push into the deque
                if(weight == 1){
                    dq.push_back(neighbor);
                } else {
                    dq.push_front(neighbor);
                }
            }
        }
    }

    fr(i, n){
        cout<<dist[i]<<" ";
    }
}

int main(){

    int n;
    cin>>n;  /// no. of vertices
    int num_edges;
    cin>>num_edges;
    int x, y, w;
    g.resize(n);
    while(num_edges--){
        cin>>x>>y>>w;
        g[x].push_back(make_pair(y, w));
        g[y].push_back(make_pair(x, w));
    }
    int t;
    cin>>t;
    int src;
    while(t--){
        cin>>src;
        ZeroOneBFS(src, n);
        cout<<endl;
    }

    return 0;
}
