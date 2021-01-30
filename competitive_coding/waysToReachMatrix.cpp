#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

ll specialMatrix(int n, int m, vector<pii>& mv){
    /// destination is n,m. To start from (1,1).
    /// mp stores blocked cells in the matrix.
    ll dp[n+1][m+1];  /// dp[i][j] stores no. of ways to reach to i,j from (1, 1).
    fr(i, n+1)
        fr(j, m+1)
            dp[i][j] = 0;
    for(auto b: mv){
        dp[b.first][b.second] = -1;  /// blocked states.
    }
    fr(i, n+1){
        if(dp[i][1] != -1)
            dp[i][1] = 1;
        else
            break;
    }
    fr(j, m+1){
        if(dp[1][j] != -1)
            dp[1][j] = 1;
        else
            break;
    }

    rep(i, 2, n){
        rep(j, 2, m){
            if(dp[i][j] == -1)
                continue;
            if(dp[i-1][j] != -1)
                dp[i][j] += dp[i-1][j]%mod;
            if(dp[i][j-1] != -1)
                dp[i][j] += dp[i][j-1]%mod;
        }
    }
    return dp[n][m]%mod;
}

int main(){
    int t, n, m, k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int a, b;
        vector<pii> mv;
        fr(i, k){
            cin>>a>>b;
            mv.push_back({a, b});
        }
        cout<<specialMatrix(n, m, mv)<<endl;
    }
    return 0;
}

