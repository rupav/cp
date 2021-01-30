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
    int n, k;
    cin>>n>>k;
    int a[n];
    fr(i, n) cin>>a[i];

    vector<bool> dp(k + 1);
    /// dp[i] = whether players with the chance in hand wins or not with i stones left
    for(int stones = 0; stones <= k; ++stones){
        repn(i, n-1, 0){
            int x = a[i];
            if(stones >= x && !dp[stones - x]){
                dp[stones] = true;
            }
        }
    }

    cout<<(dp[k] ? "First" : "Second");

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

