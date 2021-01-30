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
    int n;
    string s;
    cin>>n;
    cin>>s;

    int dp[n] = {0};  /// dp[i] = good subarrays ending at i
    int ans = 0;

    int j;
    fr(i, n){
        j = (int)(s[i] - '0');
        if(j == 1) dp[i]++;
        if(i - j + 1>= 0) dp[i] += dp[i - j + 1];
        ans += dp[i];
    }

    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

