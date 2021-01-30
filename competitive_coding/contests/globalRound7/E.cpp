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

const int N = 3e5+5;
int n;
int t[2*N];

void build(){   /// build the tree
    for(int i = n-1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

void modify(int p, int val = -1){    /// set value at pos p
    for(t[p += n] = val; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

int query(int l, int r){    /// sum of interval [l, r)
    int res = -1;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1) res = max(res, t[l++]);
        if(r&1) res = max(res, t[--r]);
    }
    return res;
}

void solve(){
    cin>>n;
    int p[n], q[n];
    map<int, int> mp;
    fr(i, n) {
        cin>>p[i];
        p[i]--;
        mp[p[i]] = i;
    }
    fr(i, n) {
        cin>>q[i];
        q[i]--;
    }

    fr(i, n) t[i] = p[i];

    int res[n];
    res[0] = n;
    int max_ = 0;   /// pos of p[i]

    rep(i, 1, n-1){
        if(q[i-1] < max_){
            /// check if already deleted
        }
        modify(query(0, mp[q[i-1]] - 1));
        res[i] = query(0, n-1) + 1;
        max_ = max(q[i-1], max_);
    }

    fr(i, n) cout<<res[i]<<" ";

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

