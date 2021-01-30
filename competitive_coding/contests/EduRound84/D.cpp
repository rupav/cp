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

void solve(){
    ll n;
    cin>>n;
    ll p[n+1];
    ll c[n+1];
    rep(i, 1, n) cin>>p[i];
    rep(i, 1, n) cin>>c[i];

    vector<bool> vis(n+1, 0);
    map<int, vector<int>> walk; /// different cycles
    rep(i, 1, n){
        if(vis[i]) continue;
        vis[i] = 1;
        int curr = i;
        walk[i].push_back(i);
        while(p[curr] != i){
            curr = p[curr];
            vis[curr] = 1;
            walk[i].push_back(curr);
        }
    }

    int ans = n;

    for(auto cyc: walk){
        int s = cyc.second.size();  /// size of the current cycle

        for(int i=1; i*i<=s; i++){
            int k = i;
            if(s%k) continue;

            /// check for k and s/k
            vector<int> poss(k, 1);
            rep(i, 0, s-1){
                if(c[cyc.second[i]] != c[cyc.second[i%k]]) poss[i%k] = 0;
            }
            if(*max_element(poss.begin(), poss.end())) ans = min(ans, k);

            k = s/k;
            poss.assign(k, 1);
            rep(i, 0, s-1){
                if(c[cyc.second[i]] != c[cyc.second[i%k]]) poss[i%k] = 0;
            }
            if(*max_element(poss.begin(), poss.end())) ans = min(ans, k);

        }
    }

    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

