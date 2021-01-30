#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
#define int ll
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    int n, x;
    cin>>n;
    map<int, int> mp;
    vector<int> a;
    set<int> s;
    fr(i, n){
        cin>>x;
        s.insert(x);
        mp[x] += x;
    }
    for(auto x: s) a.push_back(x);

    n = a.size();

    vector<int> dp(n, 0);  /// dp[i] - max. points with picking ending at a[i];
    fr(i, n) dp[i] = mp[a[i]];

    for(int i = 0; i < n; i++){
        if(mp[a[i] + 1]){
            for(int j: {i + 2, i + 3}){
                if(j < n)
                    dp[j] = max(dp[j], dp[i] + mp[a[j]]);
            }
        } else {
            for(int j: {i + 1, i + 2}){
                if(j < n)
                    dp[j] = max(dp[j], dp[i] + mp[a[j]]);
            }
        }
    }

    int ans = dp[n - 1];
    if(n > 1) ans = max(ans, dp[n - 2]);
    cout<<ans;

}

signed main(){
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

