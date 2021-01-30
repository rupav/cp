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
ll mod = 1e9+7;


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

const int N = 2e5 + 5;
ll fac[N];
ll inv[N];


void fill_(ll n, ll p = mod){
    fac[0] = 1ll;
    rep(i, 1, n) fac[i] = (ll) fac[i-1] * (i) % p;
    inv[n] = modularExponentiation(fac[n], p - 2ll, p);
    repn(i, n-1, 0) inv[i] = (ll) inv[i+1] * (i + 1ll) %p;
}

ll ncr(ll n, ll r, ll p = mod){
    if(n < 0 || r < 0 || r > n) return 0ll;
    return (((fac[n]*inv[n-r])%p)*inv[r])%p;
}

ll paths(ll a, ll b){
    return ncr(a + b, a);
}

void sub_self(ll &a, ll b){
    a -= b;
    if(a < 0) a += mod;
}

ll mul(ll a, ll b){
    return (ll) a * b % mod;
}

bool le(const pll &a, const pll &b){
    return (a.first <= b.first && a.second <= b.second);
}

void solve(){
    ll h, w, n;
    cin>>h>>w>>n;
    vector<pll> points(n+1);
    fr(i, n){
        cin>>points[i].first>>points[i].second;
    }

    fill_(h + w + 1ll);

    points[n] = {h, w}; /// dummy

    sort(points.begin(), points.end(), [&](pll &a, pll &b){
        return a.first + a.second < b.first + b.second;
    });

    vector<ll> dp(n+1, 0ll);
    /// dp[i] = no. of paths till i, such that it is the first forbidden point

    for(int i=0; i<=n; i++){
        dp[i] = paths(points[i].first - 1, points[i].second - 1);

        for(int j = 0; j < i; ++j){
            if(le(points[j], points[i])){
                sub_self(dp[i], mul(dp[j], paths(points[i].first - points[j].first, points[i].second - points[j].second)));
            }
        }
    }
    cout<<dp[n];
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

