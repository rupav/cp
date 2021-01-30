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

const int N = 1e5+ 5;
vector<vector<int>> g(N);

set<int> s;

void dfs(int v, int p, bool par, int &mx){
    int cnt = 0;    /// children count of this node which are leaves
    for(auto u: g[v]){
        if(g[u].size() == 1) cnt++;
        if(u == p) continue;
        dfs(u, v, !par, mx);
    }
    if(g[v].size() == 1) s.insert(par);
    else if(cnt) mx -= (cnt - 1);   /// paint all those edges children with one color
}

void solve(){
    int n, u, v, mx, mn;
    cin>>n;
    fr(i, n-1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mx = n-1;
    mn = 1;
    dfs(1, 1, 0, mx);
    if(s.size() > 1) mn = 3;
    cout<<mn<<" "<<mx;
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

