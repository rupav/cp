#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef unsigned long long ll;
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

ll IFa[1000010];
bool isFilled_Fa = false;
bool isFilled_IFa = false;
ll Fa[1000010];

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

void constructFa(int n, bool force = false){
    if(!force && isFilled_Fa)   /// already filled.
        return;
    Fa[0] = Fa[1] = 1;
    rep(i, 2, n){
        Fa[i] = 1ll*Fa[i-1]*i%mod;
    }
    isFilled_Fa = true;
}

void constructIFa(int n, bool force = false){
    if(!force && isFilled_IFa)   /// already constructed.
        return;
    if(!isFilled_Fa)
        constructFa(n, true);

    IFa[0] = 1;
    /// assuming FA is already constructed.
    IFa[n] = exponentiation(Fa[n], mod-2, mod);
    for(int i=n-1; i>=1; i--){
        IFa[i] = 1ll*IFa[i+1]*(i+1)%mod;
    }
    isFilled_IFa = true;
}

ll findFac(ll x, ll m){
    constructFa(x);
    return Fa[x];
}

ll findIFac(ll y, ll m){
    /// by fermat's little theorem...
    constructIFa(y);
    return IFa[y];
}

ll nCrMod(ll x, ll y, ll m = mod, bool flag = true){
    /// find modular fac and inverse to to get combinatorial modular operation!
    if(x < y)
        return 0;
    ll fac = findFac(x, m);
    ll iFac1 = findIFac(y, m);
    ll iFac2 = findIFac(x-y, m);
    return (((fac*iFac1)%m)*iFac2)%m;
}

ll solve(ll n, ll k){
    ll ans = 0;
    ll x = n*(n - 1);
    constructFa(x, true);
    constructIFa(x, true);

    ll z = 1ll;
    for(int i=x; i>=0; i--){
        ans = (ans%mod + (nCrMod(x, i)*z)%mod)%mod;
        z = (z*(k-1))%mod;
    }
    ans %= mod;
    constructFa(n, true);
    return (ans*Fa[n])%mod - 1ll;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin>>n>>k;

    cout<<solve(n, k);

    return 0;
}

