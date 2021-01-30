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
    int n;
    cin>>n;
    vector<int> dp(n + 1, INF); /// dp[i]: min steps to reach from n to i
    dp[n] =  0;

    auto dig = [&](int n){
        set<int> s;
        while(n){
            s.insert(n%10);
            n /= 10;
        }
        return s;
    };

    for(int i = n; i >= 0; i--){
        /// iterate over all its digits
        if(dp[i] == INF) continue;
        for(auto d: dig(i)){
            if(d && i - d >= 0) dp[i - d] = min(dp[i - d], dp[i] + 1);
        }
    }
    cout<<dp[0];
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

