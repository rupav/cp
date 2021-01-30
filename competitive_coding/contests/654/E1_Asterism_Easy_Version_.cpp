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
    ll n, p;
    cin>>n>>p;
    ll a[n];
    ll sm = 0ll;
    ll mx = 0ll, mn = 2e3 + 5;
    fr(i, n){
        cin>>a[i];
        mx = max(mx, a[i]);
        sm += a[i];
        mn = min(mn, a[i]);
    }
    sort(a, a + n);

    vector<ll> res;
    ll x = max(mn, mx - n + 1ll);

    

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

