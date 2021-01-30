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

void solve(){
    ll n, k;
    cin>>n>>k;
    ll h[n];
    vector<ll> dp(n, inf);
    dp[0] = 0ll;
    fr(i, n) cin>>h[i];

    fr(i, n){
        rep(j, i+1, i+k){
            if(j < n)
                dp[j] = min(dp[j], dp[i] + llabs(h[i] - h[j]));
        }
    }
    cout<<dp[n-1];
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

