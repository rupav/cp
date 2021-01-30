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
#define int ll


void solve(){
    ll n, k, x;
    cin>>n>>k;
    map<ll, ll> cnt;
    fr(i, n){
        cin>>x;
        if(x % k){
            cnt[k - (x % k)]++;
        }
    }

    ll res = 0ll;
    for(auto it: cnt){
        res = max(res, it.first + ((it.second - 1ll) * k) + 1ll);
    }

    cout<<res<<endl;
}

signed main(){
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
