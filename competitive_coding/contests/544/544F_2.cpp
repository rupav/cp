#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

const int N = (int)2e5+5;
vector<int> v[N];
bool vis[N];
set<pii> ans;
queue<int> q;

void print(bool f){
    if(f) cout<<"YES";
    else cout<<"NO";
}

void dfs(int node){
    vis[node] = true;
    for(auto it: v[node]){
        if(!vis[it])
            dfs(it);
    }
}

int main(){
    int n, m, x, y, d;
    cin>>n>>m>>d;
    fr(i, m){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        /// adjacency list created.
    }

    /// not possible for 1 to have d degree in the spanning tree.
    if(v[1].size() < d){
        print(0);
        return 0;
    }

    rep(i, 1, n) vis[i] = false;

    /// find all essential edges to 1.
    vis[1] = true;
    for(auto it: v[1]){
        if(!vis[it]){
            ans.insert(make_pair(1, it));
            dfs(it);
        }
    }

    if(ans.size() > d){
        /// can't reduce degree to d of 1, to form a spanning tree!
        print(0);
        return 0;
    }

    /// add remaining non-essential edges of 1 in the ans set.
    for(auto it: v[1]){
        if(ans.size() == d) break;
        ans.insert(make_pair(1, it));  /// same edges will be discarded, because of set property of uniqueness.
    }

    /// now we have to just make the spanning tree!
    rep(i, 1, n) vis[i] = false;
    /// bfs
    vis[1] = true;
    for(auto it: ans){
        vis[it.second] = true;
        q.push(it.second);
    }

    while(q.size()){
        int node = q.front();
        q.pop();
        for(auto it: v[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push(it);
                ans.insert(make_pair(node, it));
            }
        }
    }

    print(1);
    for(auto it: ans){
        cout<<endl<<it.first<<" "<<it.second;
    }

    return 0;
}
