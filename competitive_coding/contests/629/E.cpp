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

const int N = 2e5 + 5;
vector<pii> euler;
vector<vector<int>> g(N);
vector<int> height(N);
vector<int> st(N);

void dfs3(int v, int p = -1, int h = 0){
    euler.push_back({h, v});
    height[v] = h;
    for(auto u: g[v]){
        if(u == p) continue;
        dfs3(u, v, h+1);
        euler.push_back({h, v});
    }
}

vector<int> tin(N), tout(N);
int T = 0;
vector<int> par(N);

void dfs(int v, int p, int h = 0){
    tin[v] = T++;
    height[v] = h;
    par[v] = p;
    for(auto u: g[v]) if(u != p) dfs(u, v, h+1);
    tout[v] = T++;
}

bool check(int u, int v){
    /// checks if u and v lie on same path from root->u->v
    /// assuming v being farthest, check if u is ancestor of v
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void solve(){
    int n, m, u, v, k, x;
    cin>>n>>m;
    fr(i, n-1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 1);

    fr(i, m){
        cin>>k;
        bool f = true;
        u = 1;
        int hmax = -1;
        int val = -1;
        vector<int> v;
        fr(i, k){
            cin>>x;
            if(x == 1) continue;
            v.push_back(x);
            if(height[x] > hmax){
                hmax = height[x];
                val = x;
            }
        }
        if(~val){
            for(auto it: v){
                f = f && check(par[it], val);
            }
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

