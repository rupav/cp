#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

vector<int> g[200005];
bool vis[200005];


ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}

void dfs(vector<int> *ans, int v, bool flag){
    ans[flag].push_back(v);
    vis[v] = true;
    for(auto it: g[v]){
        if(!vis[it]) dfs(ans, it, !flag);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    int n, m;
    while(t--){
        cin>>n>>m;
        fr(i, n+1){
            vis[i] = false;
            g[i].clear();
        }

        while(m--){
            int u, v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> ans[2];
        dfs(ans, 1, false);
        bool temp = (ans[1].size() < ans[0].size());
        cout<<ans[temp].size()<<endl;
        for(auto it: ans[temp]){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}

