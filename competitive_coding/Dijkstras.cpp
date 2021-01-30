#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
using pii = pair<int, int>;
vector<vector<pii>> g;  /// graph

void Dijkstra(int s, vector<int> &d, vector<int> &p){
    int n = g.size();
    d.assign(n, INF);  /// distances from source s
    p.assign(n, -1);  /// predecessors
    d[s] = 0;
    set<pii> q;
    q.insert(make_pair(d[s], s));
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());

        for(auto neighbor: g[v]){
            /// check for relaxation condition
            if(d[neighbor.first] > d[v] + neighbor.second){
                q.erase(make_pair(d[neighbor.first], neighbor.first));
                d[neighbor.first] = d[v] + neighbor.second;
                q.insert(make_pair(d[neighbor.first], neighbor.first));
                p[neighbor.first] = v;
            }
        }
    }
}

int main(){
    return 0;
}
