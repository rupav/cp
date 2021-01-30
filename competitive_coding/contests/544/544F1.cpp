#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

template<typename T>
class Graph{
    map<T, vector<T>> E;
public:
    Graph(){
    }

    void addEdge(T u, T v, bool bi = true){
        E[u].push_back(v);
        if(bi)
            E[v].push_back(u);
    }

    T maxDegreeNode(){
        typename std::map<T, vector<T>>::iterator it = E.begin();
        int maxE = 0;
        T res;
        while(it!=E.end()){
            if(it->second.size()>=maxE){
                maxE = it->second.size();
                res = it->first;
            }
            it++;
        }
        return res;
    }

    map<T, T> bfs(T src){
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;
        for(auto v: E){
            dist[v.first] = INT_MAX;
        }
        dist[src] = 0;
        parent[src] = src;
        q.push(src);
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto neighbor: E[node]){
                if(dist[neighbor] == INT_MAX){
                    q.push(neighbor);
                    dist[neighbor] = 0;
                    parent[neighbor] = node;
                }
            }
        }
        return parent;
    }

};

int main(){
    int n, e;
    cin>>n>>e;
    int v1, v2;
    Graph<int> g;
    fr(i, e){
        cin>>v1>>v2;
        g.addEdge(v1, v2, true);  /// bidirectional edge.
    }
    int root = g.maxDegreeNode();
    map<int, int> parents = g.bfs(root);
    for(auto edge: parents){
        int parent = edge.first;
        int child = edge.second;
        if(parent != child){
            /// parent[root] = root.
            cout<<child<<" "<<parent<<endl;
        }
    }
    return 0;
}

