#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
int mat[100][100];

int maximizePathCoins(int m, int n){
    ll dp[m][n];
    /// all cells have some points, return max. points that can be collected from (0,0) cell to (m-1, n-1) cell, with right, and down movements allowed only.
    fr(i, m){
        fr(j, n){
            dp[i][j] = mat[i][j];
        }
    }
    rep(i, 1, m-1)
        dp[i][0] += dp[i-1][0];
    rep(j, 1, n-1)
        dp[0][j] += dp[0][j-1];

    rep(i, 1, m-1){
        rep(j, 1, n-1){
            dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

int main(){
    int t, r, c;
    cin>>t;
    while(t--){
        cin>>r>>c;
        fr(i, r){
            fr(j, c){
                cin>>mat[i][j];
            }
        }
        ll temp = maximizePathCoins(r, c);
        cout<<temp<<endl;
    }
    return 0;
}

