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

void max_self(ll &a, ll b){
    a = max(a, b);
}

void solve(){
    ll n, W;
    cin>>n>>W;
    vector<ll> dp(W + 1, 0ll);
    /// dp[i] = max. value with knapsack weight not exceeding i
    fr(item, n){
        ll weight, val;
        cin>>weight>>val;
        for(ll weights_already = W - weight; weights_already >= 0; weights_already--){
            max_self(dp[weights_already + weight], dp[weights_already] + val);
        }
    }

    ll ans = 0ll;
    for(ll w = 0ll; w <= W; w++){
        max_self(ans, dp[w]);
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

