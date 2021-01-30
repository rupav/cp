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
    int n;
    cin>>n;
    vector<int> c(n);
    int mx = 0; /// max sum that can be achieved!
    fr(i, n) {
        cin>>c[i];
        mx += c[i];
    }

    vector<bool> dp(mx + 1, false); /// dp[i] : If sum i can be produced using given coins
    dp[0] = 1;  /// don't use any coin

    for(auto coin: c){
        for(int sum_already = mx - coin; sum_already >= 0; sum_already--){
            dp[sum_already + coin] = dp[sum_already + coin] || dp[sum_already];
        }
    }


    cout<<accumulate(dp.begin(), dp.end(), -1)<<endl;
    rep(i, 1, mx) if(dp[i]) cout<<i<<" ";

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

