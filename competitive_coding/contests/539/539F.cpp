/// Tree
/// Used - Cayley's generalizaed formula.
/// - Stars and Bars.

#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

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
    if(!flag)
        /// condition while choosing 'e-1' vertices from 'n-2' available (excluding 'a' and 'b') and then rearranging those vertices in between!
        return fac*iFac2%m;
    return (((fac*iFac1)%m)*iFac2)%m;
}

int main(){
    int n, m, a, b;
    cin>>n>>m>>a>>b;

    ll res[5];
    ll ans = 0;
    constructFa(max(n, m)+1, true);
    constructIFa(max(n, m)+1, true);
    rep(e, 1, n-1){
        res[0] = nCrMod(m-1, e-1); /// stars and bars method for sum equal to m and e subsets.
        res[1] = nCrMod(n-2, e-1, mod, false); ///  choosing e-1 vertices from the available n-2, and then rearranging them.
        res[2] = exponentiation(m, n-e-1);  /// factor to include where each remaining vertices can assume any of the m available values.
        if(e == n-1){
            ///  when all edges are in a straight line, with end vertices as 'a' and 'b'.
            /// Then we there is only 1 way to hang remaining (0) vertices onto the assumed fixed path.
            res[3] = 1ll;
            res[4] = 1ll;
        } else {
            /// find no. of ways to hang remaining vertices on the fixed path vertices (or e+1 components of the forest) using cayley generalized formula.
            res[3] = e+1;
            res[4] = exponentiation(n, n-e-2);
        }

        rep(i, 1, 4){
            res[0] = (res[i]*res[0])%mod;
        }

        ans += (res[0])%mod;

    }

    cout<<ans%mod;

    return 0;
}
