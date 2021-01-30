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

vector<int> r;
vector<int> c;
int mp[1005][1005];



ll modularExponentiation(ll x, ll y, ll p = mod){
    if(y==0)
        return 1;
    if(y == 1)
        return x;
    if(y&1){
        /// y is odd, so (x*(x^(y-1)))%p
        return (x*modularExponentiation(x, y-1, p))%p;
    } else {
        /// y is even, so (x^(y/2))^2
        ll c = modularExponentiation(x, y/2, p);
        return (c*c)%p;
    }
}

ll exponentiation(ll x, ll y, ll mod = mod){
    x = x%mod;
    ll res = 1;
    while(y>0){
        if(y&1){
            res = (res*x)%mod;
        }
        y = y>>1;  /// y/=2
        x = (x*x)%mod;
    }
    return res;
}


ll solve(int n, int m){
    fr(i, n){
        fr(j, r[i]){
            mp[i][j] = 1;
        }
        if(r[i] < m) mp[i][r[i]] = 0; /// has to be clear!
    }

    fr(j, m){
        fr(i, c[j]){
            if(mp[i][j] == 0){
                return 0;  /// not possible now
            }
            mp[i][j] = 1;
        }
        if(mp[c[j]][j] == 1) return 0;   /// it has to be 0, or untouched!
        if(c[j] < n) mp[c[j]][j] = 0; /// has to be clear
    }

    /// now the rest -1 has to be filled
    int cnt = 0;
    fr(i, n) fr(j, m) if(mp[i][j] == -1) cnt++;

    return exponentiation(2ll, cnt*1ll);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    r.resize(n);
    c.resize(m);
    fr(i, n) fr(j, m) mp[i][j] = -1;

    fr(i, n) cin>>r[i];
    fr(i, m) cin>>c[i];

    cout<<solve(n, m)<<endl;

    return 0;
}

