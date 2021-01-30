///For instance, suppose we are given a tree with N nodes and a weight assigned to each node, along with a number K. The aim is to delete enough nodes from the tree so that the tree is left with precisely K leaves. The cost of such a deletion is the sum of the weights of the nodes deleted. What is the minimum cost to reduce to tree to a tree with K leaves?
/// https://www.iarcs.org.in/inoi/online-study-material/topics/dp-trees.php

#include<bits/stdc++.h>
using namespace std;
#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)

vector<vector<int>> g;  /// graph
vector<int> weights;  /// weight of nodes.
vector<int> sum;
vector<int> lvs;   /// no. of leaves for subtree rooted at v.

void fillSum(int v){
    int temp = 0;
    bool flag = true;
    lvs[v] = 0;
    for(auto u: g[v]){
        fillSum(u);
        temp += sum[u];
        flag = false;
        lvs[v] += lvs[u];
    }
    sum[v] = weights[v] + temp;
    lvs[v] = max(1, lvs[v]);
    return;
}

int dfs(int v, int k){
    if(k == 0) return sum[v];  /// delete that tree

    int m = g[v].size();
    int c[m+1][k+1];  /// c[m, j] is min. cost of reducing T[w1],.. T[wM] with j leaves
    int i = 0;
    for(auto u: g[v]){
        i++;
        c[i][0] = sum[v] - weights[v];  /// deleting all children
        rep(j, 1, k){
            if(i == 1)
                c[1][j] = dfs(u, j);   /// if we have only 1 child!
            else {
                c[i][j] = INT_MAX;
                rep(l, 0, j){
                    c[i][j] = min(c[i-1][j-l] + dfs(u, l), c[i][j]);
                }
            }
        }
    }

    if(k == 1) return min(sum[v] - weights[v], c[m][1]);
    return c[m][k];
}

int minCostReducingToKLeaves(int n, int k){
    /// root is 0, graph is a tree
    sum.assign(n, 0);  /// sum of subtree rooted at v;
    lvs.assign(n, 0);
    fillSum(0);
    if(lvs[0] < k) return -1;
    return dfs(0, k);
}

int main(){
    int n, m, k, q, x, u, v;
    cin>>n>>m>>q;
    g.resize(n);
    weights.resize(n);

    fr(i, n){
        cin>>x;
        weights[i] = x;
    }

    fr(i, m){
        cin>>u>>v;
        g[u].push_back(v);  /// its a tree, rooted at 0.
    }

    while(q--){
        /// find min cost for each k;
        cin>>k;
        cout<<minCostReducingToKLeaves(n, k)<<endl;
    }

    return 0;
}

