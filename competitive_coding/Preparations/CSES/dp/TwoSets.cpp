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

void add_self(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}

void solve(){
    int n;
    cin>>n;
    int mx = (n * (n + 1)) / 2;
    vector<int> dp(mx/2+ 1, 0);  /// dp[i] no. of ways to get sum i
    dp[0] = 1;

    /// don't consider last element, this way we ensure its in second set, and thus unique combination.
    rep(i, 1, n - 1){
        for(int already_ways = mx/2 - i; already_ways >= 0; --already_ways){
            add_self(dp[already_ways + i], dp[already_ways]);
        }
    }

    cout<<((mx & 1) ? 0 : dp[mx/2]);

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

