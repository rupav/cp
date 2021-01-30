#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void bfs(int s, int n){
    queue<int> q;
    vector<bool> used(n);
    vector<int> d(n), p(n);

    q.push(s);
    p[s] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        used[s] = true;
        for(auto it: adj[v]){
            if(!used[it]){
                q.push(it);
                d[it] = d[v] + 1;
                p[it] = v;
            }
        }
    }

}

int main(){
    return 0;
}
