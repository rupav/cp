#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

class Graph{
    int V;
    int **dp;
public:
    Graph(int v){
        V = v;
        dp = new int*[V];
        fr(i, V){
            dp[i] = new int[V];
            fr(j, V){
                dp[i][j] = 0;  /// initialization.
            }
        }
    }
    void addEdge(int u, int v, int w=1, bool bi = true){
        dp[u][v] = w;
        if(bi)
            dp[v][u] = w;
    }
    void printAdjacencyMatrix(){
        fr(i, V){
            fr(j, V){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(0, 1);
    g.addEdge(3, 4);
    g.addEdge(0, 4);
    g.addEdge(0, 3);
    g.printAdjacencyMatrix();
    return 0;
}

