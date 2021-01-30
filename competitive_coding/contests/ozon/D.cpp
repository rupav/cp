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

int N = 1e3 + 5;
vector<set<int>> g(N);
vector<pii> v(N);
vector<int> p(N);
vector<bool> vis(N);

pii dfs(int src, int par, int dist = 0){
    pii res = {dist, src};
    for(auto u: g[src]){
        if(u != par){
            res = max(res, dfs(u, src, dist+1));
            p[u] = src;
        }
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    v.resize(n);
    p.resize(n);
    vis.assign(n, false);
    g.resize(n);
    int u, x;
    fr(i, n-1){
        cin>>u>>x;
        u--;
        x--;
        g[u].insert(x);
        g[x].insert(u);
    }


    int src = 0;
    while(true){
        if((int)g[src].size() == 0){
            cout<<"! "<<src+1;
            return;
        }

        p[src] = src;
        pii res = dfs(src, src, 0);
        p[res.second] = res.second;
        pii res2 = dfs(res.second, res.second, 0);

        cout<<"? "<<res.second + 1<<" "<<res2.second + 1<<endl;
        cin>>x;
        x--;
        if(x == res.second || x == res2.second){
            cout<<"! "<<x+1;
            return;
        }

        /// remove edges from x to its neighbors
        int par = res2.second;
        vis.assign(n, false);
        while(par != p[par]){
            vis[par] = true;
            par = p[par];
        }
        vis[par] = true;

        vector<int> del;
        for(auto it: g[x]){
            if(vis[it]) {
                del.push_back(it);
            }
        }

        for(auto it: del){
            g[x].erase(g[x].find(it));
        }

        src = x;
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

/*
8
3 2
2 7
7 6
6 4
4 5
6 1
1 8

4
*/

