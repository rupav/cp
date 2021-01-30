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

/// https://www.codechef.com/JUNE20A/problems/EOEO


void solve(){
    ll ts;
    cin>>ts;
    int p = 0;  /// ts = 2^p . q
    ll t = ts;
    while((t % 2ll) == 0){
        t /= 2ll;
        p++;
    }

    /// JS : 2^(p+1) . y where y >= 1 and JS <= TS.
    ll fac = (1ll << (p + 1ll));
    ll y = ts / fac;
    if(fac * y > ts) y--;

    cout<<y<<endl;
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

