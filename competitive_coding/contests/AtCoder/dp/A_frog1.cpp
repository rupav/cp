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

const ll inf = numeric_limits<ll>::max();

void solve_2(){
    ll n;
    cin>>n;
    ll h[n];
    fr(i, n) cin>>h[i];
    vector<ll> dp(n, inf);
    dp[0] = 0;
    fr(i, n){
        for(auto j: {i+1, i+2}){
            if(j < n){
                dp[j] = min(dp[j], dp[i] + llabs(h[i] - h[j]));
            }
        }
    }
    cout<<dp[n-1];
}

void solve(){
    ll n;
    cin>>n;
    ll h[n + 1], dp[n+1][2];

    rep(i, 1, n) cin>>h[i];

    dp[1][0] = dp[1][1] = 0;
    dp[2][0] = 0ll + llabs(h[2] - h[1]);
    dp[2][1] = inf;

    rep(i, 3, n){
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + llabs(h[i] - h[i-1]);
        dp[i][1] = min(dp[i-2][0], dp[i-2][1]) + llabs(h[i] - h[i-2]);
    }

    cout<<min(dp[n][0], dp[n][1]);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve_2();
    }

    return 0;
}

