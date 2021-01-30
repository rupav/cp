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

void min_self(int &a, int b){
    a = min(a, b);
}

void solve(){
    string s, t;
    cin>>s>>t;
    int n(s.size()), m(t.size());

    /// dp[i][j] = Edit Distance for prefixes of s and t resp. with size i & j resp.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            int &z = dp[i][j];
            if(i > 0) min_self(z, dp[i - 1][j] + 1);    /// deleted character s[i]
            if(j > 0) min_self(z, dp[i][j - 1] + 1);    /// appended character t[j] to s
            if(i && j){
                if(s[i - 1] == t[j - 1]) min_self(z, dp[i - 1][j - 1]);
                else min_self(z, dp[i - 1][j - 1] + 1); /// replace
            }
        }
    }

    cout<<dp[n][m];
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

