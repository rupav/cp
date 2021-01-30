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
    double p, q;
    cin>>n;
    vector<double> dp(n + 1, 0);   /// probability that i coins has been tossed so far
    dp[0] = 1;

    for(int coin = 0; coin < n; ++coin){
        cin>>p;
        q = 1.0 - p;

        for(int tossed_so_far = coin; tossed_so_far >= 0; tossed_so_far--){
            dp[tossed_so_far + 1] += dp[tossed_so_far] *  p;
            dp[tossed_so_far] = dp[tossed_so_far] * q;
        }
    }

    double ans = 0.0;
    rep(heads, 1, n){
        int tails = n - heads;
        if(heads > tails) ans += dp[heads];
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

