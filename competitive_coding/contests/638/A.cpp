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


void solve(){
    ll n;
    cin>>n;
    ll val = 2ll;
    vector<ll> el(n);

    fr(i, n) {
        el[i] = val;
        val *= 2ll;
    }

    ll ans = el[n-1];
    fr(i, n/2 - 1){
        ans += el[i];
    }
    rep(i, n/2 - 1, n-2) ans -= el[i];
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

