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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

vector<vector<int>> g;
vector<bool> vis;
int max_ = 0;
int min_ = INT_MAX;

void dfs(int v){
    vis[v] = true;
    max_ = max(max_, v);
    min_ = min(min_, v);
    for(auto u: g[v]){
        if(!vis[u])
            dfs(u);
    }
    vis[v] = true;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1, false);
    int u, v;
    fr(i, m){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    u = 1;
    vector<pii> x;
    while(u<=n){
        if(!vis[u]){
            dfs(u);
            x.push_back({min_, max_});
            min_ = n+1;
            max_ = 0;
        }
        u++;
    }

    sort(x.begin(), x.end());
    max_ = x[0].second;
    for(int i=1; i<x.size(); i++){
        if(x[i].first < max_){
            cnt++;
        }
        max_ = max(max_, x[i].second);
    }
    cout<<cnt;

    return 0;
}

