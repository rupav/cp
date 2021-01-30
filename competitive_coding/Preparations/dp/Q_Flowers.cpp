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

const int nax = 2e5 + 5;
ll bit[nax];
/// BIT on the height of the flowers

void update(ll i, ll upd){
    for(; i < nax; i += i&(-i)) bit[i] = max(bit[i], upd);
}

ll get_max(ll i){
    ll mx = bit[i];
    for(; i > 0; i -= i&(-i)) mx = max(mx, bit[i]);
    return mx;
}


void solve(){
    int n;
    cin>>n;
    vector<ll> h(n), a(n);
    fr(i, n) cin>>h[i];
    fr(i, n) cin>>a[i];

    ll ans = 0ll;
    fr(i, n){
        /// for each element find the max sum with last element as a[i]
        ll mx = get_max(h[i]);
        update(h[i], mx + a[i]);
        ans = max(ans, mx + a[i]);
    }
    cout<<ans;
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

