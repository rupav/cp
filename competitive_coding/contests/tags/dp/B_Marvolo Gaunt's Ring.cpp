#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

#define INF mod

int main(){
    ll n, p, q, r;
    cin>>n>>p>>q>>r;
    ll a[n];
    fr(i, n) cin>>a[i];
    ll dp[n][3];

    dp[0][0] = p*a[0];
    dp[0][1] = dp[0][0] + q*a[0];
    dp[0][2] = dp[0][1] + r*a[0];

    rep(i, 1, n-1){
        dp[i][0] = max(dp[i-1][0], p*a[i]);
        dp[i][1] = max(dp[i-1][1], q*a[i] + dp[i][0]);
        dp[i][2] = max(dp[i-1][2], r*a[i] + dp[i][1]);
    }

    cout<<dp[n-1][2];

}
