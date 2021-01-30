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
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    vector<int> dp(n + 1, -1);  /// dp[i] = max. no. of pieces of total size n
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j: {a, b, c}){
            if(~dp[i] && i + j <= n){
                dp[i + j] = max(dp[i + j], dp[i] + 1);
            }
        }
    }
    cout<<dp[n];
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

