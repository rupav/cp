#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 998244353;


const int N = 2e5 + 5;
ll fac[N];
ll inv[N];

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

void fill_(ll n, ll p = mod){
    fac[0] = 1ll;
    rep(i, 1, n) fac[i] = (fac[i-1]*1ll*(i))%p;
    inv[n] = modularExponentiation(fac[n], p - 2ll, p);
    repn(i, n-1, 0) inv[i] = (inv[i+1]*1ll*(i + 1ll))%p;
    return;
}

ll ncr(ll n, ll r, ll p = mod){
    return (((fac[n]*inv[n-r])%p)*inv[r])%p;
}


/// paint n blocks in m colors, such that at most K pairs of adjacent blocks are painted in same color.
void solve(){
    ll n, m, k;
    cin>>n>>m>>k;
    fill_(n);

    ll ans = 0ll;
    ll temp;
    for(ll i = 0; i <= k; i++){
        temp = ((m*ncr(n - 1ll, i))%mod*modularExponentiation(m-1ll, n - 1ll - i))%mod;
        ans = (ans + temp)%mod;
    }

    cout<<(ans + mod)%mod;

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

