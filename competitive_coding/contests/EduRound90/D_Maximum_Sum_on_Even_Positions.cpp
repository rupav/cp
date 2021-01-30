#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pair<ll, ll>> pll;
ll mod = 1e9+7;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    fr(i, n) cin>>a[i];
    /// subarray chosen can be of only even length

    ll res = 0ll;
    ll tot = 0ll;
    fr(i, n) if(!(i&1)) res += a[i];    /// without any rotation
    tot = res;

    ll mx = 0ll, sm = 0ll;
    int i = 0;
    while(i + 1 < n){
        sm += (a[i + 1] - a[i]);
        if(sm < 0) sm = 0ll;
        mx = max(sm, mx);
        i += 2;
    }
    res = max(res, tot + mx);

    mx = 0ll, sm = 0ll;
    i = 1;
    while(i + 1 < n){
        sm += (a[i] - a[i + 1]);
        if(sm < 0) sm = 0ll;
        mx = max(sm, mx);
        i += 2;
    }
    res = max(res, tot + mx);

    cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll tc = 1;
    cin>>tc;
    while(tc--){
        solve();
    }

    return 0;
}

