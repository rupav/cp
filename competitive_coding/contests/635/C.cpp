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
vector<int> h, ch_cnt;
vector<ll> contrib;
vector<vector<int>> g;
vector<bool> mark;

int dfs(int v, int p, int ht){
    int cnt = 0;
    for(auto u: g[v]){
        if(u == p) continue;
        cnt += dfs(u, v, ht+1);
    }
    ch_cnt[v] = cnt;
    h[v] = ht;
    contrib[v] = 1ll*(cnt - ht);
    return cnt+1;
}

bool comp(pii a, pii b){
    if(a.second < b.second) return true;
    if(a.second == b.second){
        return a.first > b.first;
    }
    return false;
}

ll calc(int v, int p){
    if(mark[v]){
        return 1ll*h[v]*1ll*(ch_cnt[v] + 1);
    }

    ll res = 0ll;
    for(auto u: g[v]){
        if(u == p) continue;
        res += calc(u, v);
    }
    return res;
}

ll solve(){
    int n, k, u, v;
    cin>>n>>k;
    h.resize(n);
    ch_cnt.resize(n);
    contrib.resize(n);
    g.resize(n);
    fr(i, n-1){
        cin>>u>>v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0, 0);


    priority_queue<pll> pq;
    pq.push({contrib[0], 0});
    mark.resize(n);
    mark.assign(n, true);

    ll res = 0ll;
    ll val = n;
    vector<bool> vis(n, false);

    while(!pq.empty()){
        pll el = pq.top();
        vis[el.second] = true;
        mark[el.second] = false;
        pq.pop();

        for(auto it: g[el.second]){
            if(!vis[it])
                pq.push({contrib[it], it});
        }

        val--;
        if(val == k) break;
    }

    // fr(i, n) cout<<mark[i]<<" ";

    return calc(0, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        cout<<solve();
    }

    return 0;
}
