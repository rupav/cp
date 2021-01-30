#include<bits/stdc++.h>
using namespace std;


void dfsUtil(int src, int n, vector<int> adj[], stack<int>& s, bool *visited){
    visited[src] = true;

    for(auto it: adj[src]){
        if(!visited[it]) dfsUtil(it, n, adj, s, visited);
    }

    s.push(src);
}

int* topoSort(int V, vector<int> adj[]){
    stack<int> s;
    bool *visited = new bool[V];
    for(int i=0; i<V; i++){
        if(!visited[i]) dfsUtil(i, V, adj, s, visited);
    }

    int *ans = new int[V];
    int i=0;
    while(!s.empty()){
        ans[i++] = s.top();
        s.pop();
    }
    return ans;
}

int main(){
    return 0;
}


