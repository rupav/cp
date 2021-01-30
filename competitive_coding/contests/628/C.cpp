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

using pii = pair<int, int>;
vector<int> p;  /// storing parents of each node
vector<vector<int>> g;  /// sparse graph
pii dfs(int v, int par, int dist = 0) {
    p[v] = par;
    pii res = {dist, v};
    for(auto u: g[v]){
        if(u != par) res = max(res, dfs(u, v, dist + 1));
    }
    return res;
}

void solve(){
    int n, u, v;
    cin>>n;
    g.resize(n+1);
    p.resize(n+1);

    map<pii, int> mp;
    fr(i, n-1){
        cin>>u>>v;

        mp[{u, v}] = i;
        mp[{v, u}] = i;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(n == 2){
        cout<<0;
        return;
    }

    pii res1 = dfs(1, 1);
    pii res2 = dfs(res1.second, res1.second);
    vector<int> ans(n-1, -1);

    /// dia is greater than 1
    int val = 3;
    ans[mp[{res2.second, p[res2.second]}]] = 0;
    int curr = p[res2.second];
    if(res2.first == n-1){
        /// whole chain!
        if(n > 3){
            ans[mp[{curr, p[curr]}]] = 2;
            curr = p[curr];
        }
    }




    while(curr != p[curr]){

        ans[mp[{curr, p[curr]}]] = val++;
        curr = p[curr];
    }

    val -= 2;

    ans[mp[{g[res1.second][0], res1.second}]] = 1;
    set<int> s;


    rep(i, 0, n-2) {
        s.insert(i);
    }

    rep(i, 0, n-2) {
        if(~ans[i]) {
            s.erase(ans[i]);
        }
    }

    rep(i, 0, n-2){
        if(~ans[i]) cout<<ans[i]<<endl;
        else {
            cout<<*s.begin()<<endl;
            s.erase(s.begin());
        }
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


