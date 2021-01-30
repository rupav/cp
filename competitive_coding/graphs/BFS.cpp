#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

template<typename T>
class Graph{
    map<T, vector<T> > E;
public:
    Graph(){
    }
    void addEdge(T u, T v, bool bi = true){
        E[u].push_back(v);
        if(bi)
            E[v].push_back(u);
    }
    void print(){
        /// typename std::map<T, vector<T> >::iterator it = E.begin();
        for(auto v: E){
            cout<<v.first<<" -> ";
            for(auto e: v.second){
                cout<<e<<", ";
            }
            cout<<endl;
        }
    }

    int findDegree(T src){
        if(!E[src].empty())
            return E[src].size();
        return 0;
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

    void bfs(T src){
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;
        for(auto v: E){
            dist[v.first] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        parent[src] = src;   /// parent of its own, instead of NIL.
        cout<<endl<<"BFS order is: "<<endl;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" -> ";
            for(auto neighbor: E[node]){
                if(dist[neighbor] == INT_MAX){  /// checking unvisited nodes only.
                    q.push(neighbor);
                    dist[neighbor] = dist[node]+1;
                    parent[neighbor] = node;
                }
            }
        }
    }

    void dfsHelper(T node, map<T, bool> &visited){
        visited[node] = true;
        cout<<node<<" -> ";
        for(auto neighbor: E[node]){
            if(!visited[neighbor])
                dfsHelper(neighbor, visited);
        }
    }

    void dfs(T src){
        map<T, bool> visited;
        cout<<endl<<"DFS order is: "<<endl;
        dfsHelper(src, visited);
    }
};

int main(){
    Graph<int> g;
    int u, v;
    while(true){
        cin>>u>>v;
        if(u<0 || v<0)
            break;
        g.addEdge(u, v);
    }
    g.print();
    int src;
    cin>>src;
    g.bfs(src);
    g.dfs(src);
    return 0;
}

