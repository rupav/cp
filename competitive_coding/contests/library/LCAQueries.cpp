/// Tested for n, m === 5e5
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

const int N = 5e5 + 5;
vector<int> height(N), par(N), st(N);
vector<pii> euler;
vector<vector<int>> g(N);

/// Euler tour type - 3
void dfs_euler3(int v, int p, int h = 0){
    par[v] = p;
    height[v] = h;
    euler.push_back({h, v});
    for(auto u: g[v]){
        if(p == u) continue;
        dfs_euler3(u, v, h+1);
        euler.push_back({h, v});
    }
}


pii t[8*N];

void build(int node, int tl, int tr){
    if(tr == tl) return void(t[node] = euler[tl]);
    int tm = (tl + tr)>>1;
    build(2*node, tl, tm);
    build(2*node + 1, tm+1, tr);
    t[node] = min(t[2*node], t[2*node + 1]);
}

pii get_min(int node, int tl, int tr, int l, int r){
    if(l > r) return {INT_MAX, 0};
    if(tl == l && tr == r) return t[node];
    int tm = (tl + tr)>>1;
    return min(get_min(2*node, tl, tm, l, min(r, tm)),
               get_min(2*node + 1, tm+1, tr, max(l, tm+1), r));
}

void solve(){
    int n, m, u, v, parent;
    cin>>n>>m;

    rep(i, 1, n - 1) {
        cin>>parent;
        g[parent].push_back(i);
    }

    dfs_euler3(0, 0);
    build(1, 0, euler.size() - 1);
    repn(i, euler.size() - 1, 0){
        st[euler[i].second] = i;    /// first occurence of each element in euler - 1 -based indexing
    }

    /// queries of lca
    fr(i, m){
        cin>>u>>v;
        cout<<get_min(1, 0, euler.size() - 1, min(st[u], st[v]), max(st[v], st[u])).second<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll tc = 1;
    //  cin>>t;
    while(tc--){
        solve();
    }

    return 0;
}


