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


void solve(){
    int n;
    cin>>n;
    vector<double> dp(n+1, 0);
    /// dp[i] = prob that i heads has been tossed so far
    dp[0] = 1;
    for(int coin = 0; coin < n; coin++){
        double ph;
        cin>>ph;
        for(int i = coin; i>=0; --i){
            dp[i+1] += dp[i]*ph;
            dp[i] = dp[i]*(1 - ph); /// coin being tossed is taken as tail
        }
    }
    double ans = 0.0;
    for(int heads=0; heads<=n; heads++){
        int tails = n - heads;
        if(heads > tails) ans += dp[heads];
    }

    cout<<setprecision(11)<<ans;
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

