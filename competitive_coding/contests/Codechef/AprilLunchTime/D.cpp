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

/// https://www.codechef.com/LTIME83B/problems/MEXUM

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    map<ll, ll>;
    ll mx;
    fr(i, n) {
        cin>>a[i];
        mp[a[i]]++;
        mx = max(a[i], mx);
    }
    sort(a, a+n);



    ll ans = 0ll;

    ans = mE(2, n, mod)*1ll;

    ll pref = mp[1];
    rep(i, 2, mx){
        if(mp[i] == 0){
            break;
        } else {
            /// answer is i
            ans = (ans + ((((mE(2, pref) - 1 + mod)%mod*mE(2, n - pref - mp[i]))%mod)*i)%mod)%mod;
        }
        pref += mp[i];
    }

    cout<<ans;

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

