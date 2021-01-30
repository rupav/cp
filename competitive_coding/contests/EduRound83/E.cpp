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

void min_self(int &a, int b){
    a = min(a, b);
}

void solve(){
    int n;
    cin>>n;
    int a[n];
    fr(i, n) cin>>a[i];

    vector<vector<int>> dp(n, vector<int>(n, -1));
    /// dp[i][j] - value the whole segment can be merged into, or -1 if that's now possible
    /// To prove uniqueness, consider
    /// Lets say there are two values of K, i.e K1 and K2 (K1 < K2), such that dp(i, K1) = dp(K1 + 1,j) = X and dp(i, K2) = dp(K2 + 1, j) = Y.
    /// Then since K1 < K2, i.e. (i, K1) is a prefix of (i, K2) => Y has to be greater than X, Y > X.
    /// But with suffix, (K2+1, j) is a suffix of (K1 + 1, j) => X has to be greater than Y, which is a contradiction!
    /// Thus if possible there exists only 1 'k' to combine [i..j]! => thus uniqueness follows.

    fr(i, n) dp[i][i] = a[i];
    int cnt = 1;

    repn(i, n - 2, 0){
        rep(j, i + 1, n - 1){
            cnt = 0;
            rep(k, i, j - 1){
                if(~dp[i][k] && dp[i][k] == dp[k+1][j]){
                    cnt++;
                    dp[i][j] = dp[i][k] + 1;
                }
            }
            assert(cnt <= 1);
        }
    }

    /// Now that we have checked if segment a[i...j] is merge-able or not, we need to find minimum partitions of array into segments in which each segment can be transferred into single element!
    vector<int> dp2(n + 1, INT_MAX); /// dp[i] = min. partitions with prefix size i considered.
    dp2[0] = 0;

    for(int i = 0; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int z = (~dp[i + 1 - 1][j - 1]) ? 1: j - i;
            min_self(dp2[j], dp2[i] + z);
        }
    }

    cout<<dp2[n]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

