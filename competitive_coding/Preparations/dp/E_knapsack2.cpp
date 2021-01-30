/// same problem as Knapsack 1, but now W can be 1e9 max.
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

const int maxV = 1e3;
const ll inf = 1e18l;

void min_self(ll &a, ll b){
    a = min(a, b);
}

void solve(){
    ll n, W;
    cin>>n>>W;

    /// dp[i] = the min. total weight required with total value exactly i
    vector<ll> weight(n), val(n);
    fr(i, n) cin>>weight[i]>>val[i];
    ll sum = 0ll;
    for(auto x: val) sum += x;

    vector<ll> dp(sum + 1ll, inf);
    dp[0] = 0ll;    /// not taking any element, we can get val 0

    fr(item, n){
        for(ll value_already = sum - val[item]; value_already >= 0; value_already--){
            min_self(dp[value_already + val[item]], dp[value_already] + weight[item]);
        }
    }

    ll ans = 0;
    for(ll v = 0ll; v <= sum; v++){
        if(dp[v] <= W){
            ans = v;
        }
    }

    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    ll lim = numeric_limits<ll>::max();
    // watch(lim);

    while(t--){
        solve();
    }

    return 0;
}

