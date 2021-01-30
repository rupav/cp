#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)

class Graph{
    int V;
    vector<int> *E;

public:
    Graph(int v){
        V = v;
        E = new vector<int>[V];  /// vector of V nodes for storing their edges.
    }

    void addEdge(int u, int v, bool bi = true){
        E[u].push_back(v);
        if(bi)
            E[v].push_back(u);
    }

    void printAdjacencyList(){
        fr(i, V){
            cout<<i<<" -> ";
            for(auto v: E[i]){
                cout<<v<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5);  /// nodes 0 to 4.
    g.addEdge(0, 4);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.printAdjacencyList();
    return 0;
}
