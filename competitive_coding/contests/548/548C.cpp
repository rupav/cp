#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll MOD = 1e9+7;
int vertices = 100005;
vector< vector<int>> g(vertices);
vector<bool> vis(vertices);
ll cnt = 0;


ll power(ll a, ll b){
    if(b==0) return 1;
    ll c = power(a, b>>1);
    c = (c*c)%MOD;
    if(b&1) return (c*a)%MOD;
    return c;
}

void dfs(int node){
    vis[node] = true;
    cnt++;
    for(auto neighbor: g[node]){
        if(!vis[neighbor])
            dfs(neighbor);
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    g.resize(n+1);
    int v1, v2, c;
    fr(i, n-1){
        cin>>v1>>v2>>c;
        if(!c){
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
    }

    ll res = 0;
    for(int node=1; node<=n; node++){
        if(!vis[node]){
            dfs(node);
            res = (res + power(cnt, k))%MOD;
            cnt = 0;
        }
    }

    cout<< (power(n, k) - res + MOD)%MOD;

    return 0;
}

