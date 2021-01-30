#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7ll;

ll modularExponentiation(ll x, ll y, ll p = mod){
    if(y == 0ll)
        return 1ll;
    if(y == 1ll)
        return x % mod;
    if(y&1){
        /// y is odd, so (x*(x^(y-1)))%p
        return (x*modularExponentiation(x, y-1, p))%p;
    } else {
        /// y is even, so (x^(y/2))^2
        ll c = modularExponentiation(x, y/2, p);
        return (c*c)%p;
    }
}

void solve(){
    ll n, p;
    cin>>n>>p;
    ll a[n];
    ll b[n];
    ll sm = 0ll;
    ll zero = 0;
    fr(i, n) {
        cin>>a[i];
        b[i] = a[i];

        if(a[i] == 0) {
            // b[i] = 1ll;
            zero++;
        }

        sm += b[i];
    }

    if(p == 1){
        cout<<(n&1ll)<<endl;
        return;
    }

    /// find best partition A, B where A can be empty!
    ll curr = 0ll;
    ll dp[n] = {0ll};   /// dp[i] = A: [0...i-1] & B: [i...n-1], stores abs diff between A & B
    dp[0] = sm;
    ll suff = 0ll;

    rep(i, 1, n-1){
        curr += b[i - 1];
        suff = sm - curr;
        dp[i] = llabs(suff - curr);
        // watch(dp[i]);
    }

    ll mn = sm, ind = 0ll;
    rep(i, 1, n - 1){
        if(dp[i] <= mn){
            mn = dp[i];
            ind = i;
        }
    }

    vector<ll> poss;
    ll cnt = 0;
    int mx = zero;
    rep(i, 0, n - 1){
        if(i > 0 && a[i - 1] == 0) {
            cnt++;
            zero--;
        }
        ll d = llabs(cnt - zero);
        if(dp[i] == mn){
            if(d <= mx){
                mx = d;
                ind = i;
            }
        }
    }


    ll pref = 0ll;
    suff = 0ll;

    rep(i, 0, ind - 1){
        pref = (pref + modularExponentiation(p, a[i]))%mod;
    }

    rep(i, ind, n - 1){
        suff = (suff + modularExponentiation(p, a[i]))%mod;
    }



    cout<<(llabs(suff - pref))%mod<<endl;

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

