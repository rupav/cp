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
ll mod = 1e9+7;


void solve(){
    ll n, x;
    cin>>n>>x;
    ll a[n + 1];
    rep(i, 1, n) cin>>a[i];
    rep(i, 1, n) a[i] %= x;
    /// longest prefix or suffix is the answer
    ll pref = -1, sm = 0ll, suff = -1;

    rep(i, 1, n){
        sm += a[i];
        sm %= x;
        if(sm) pref = i;
    }

    sm = 0ll;
    repn(i, n, 1){
        sm += a[i];
        sm %= x;
        if(sm) suff = n - i + 1;
    }

    cout<<max(pref, suff)<<endl;

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

