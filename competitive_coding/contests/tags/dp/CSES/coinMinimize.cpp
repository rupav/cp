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

#define INF INT_MAX

void solve(){
    int n, x;
    cin>>n>>x;
    int c[n];
    fr(i, n) cin>>c[i];
    vector<int> dp(x + 1, INF);  /// dp[i] = min coins to reach i value
    dp[0] = 0;
    for(int coin: c){
        for(int i = 0; i + coin <= x; i++){
            if(dp[i] < INF) dp[i + coin] = min(dp[i + coin], dp[i] + 1);
        }
    }
    cout<<((dp[x] == INF) ? -1 : dp[x]);
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

