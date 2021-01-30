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
const ll INF = 1e18L + 5;

/// https://www.codechef.com/LTIME84A/problems/ABSNX
/// MIN MAX

void solve(){
    ll n, x;
    cin>>n;
    ll a[n + 1];

    ll ans = 0ll;
    ll dp[n + 1][2];    /// max increasing and decreasing length ending at i
    dp[0][0] = 0ll;
    dp[0][1] = 0ll;

    ll prev[2] = {INF, 0ll};    /// prev for max and min
    rep(i, 1, n) {
        cin>>a[i];
        x = a[i];

        if(x >= prev[0]){
            dp[i][0] = dp[i - 1][0] + 1ll;
        } else {
            dp[i][0] = 1ll;
        }

        if(x <= prev[1]){
            dp[i][1] = dp[i - 1][1] + 1ll;
        } else {
            dp[i][1] = 1ll;
        }

        ans += dp[i][0] + dp[i][1] - 1ll;

        prev[0] = prev[1] = x;
    }

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

