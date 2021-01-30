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

const int N = 1e5+1;
vector<vector<int>> g;
int dp[N]; // saves the no. of children/grandchildren and so on for each vertex

int res, n, x, y;

int calc(int v, int p){
    int &z = dp[v];
    z++;
    for(auto u: g[v]){
        if(u == p) continue;
        z += calc(u, v);
    }
    if(z%2 == 0 && v != p){
        res++;
    }
    return z;
}

int main(){
    cin>>n;
    g.resize(n+1);
    fr(i, n-1){
        cin>>x>>y;
        g[y].push_back(x);
        g[x].push_back(y);
    }
    res = 0;
    calc(1, 1);
    // rep(i, 1, n) cout<<dp[i]<<" ";
    if(n&1) res = -1;
    cout<<res;

    return 0;
}
