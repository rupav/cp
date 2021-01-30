#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;

int main(){
    int n;
    cin>>n;
    int a[n+1];
    rep(i, 1, n) cin>>a[i];
    int dp[n+1][3];  /// to maximize working days, thus minimizing rest days itself.
    fr(i, n+1){
        fr(j, 3) dp[i][j] = -1; // initialize
    }
    fr(i, 3) dp[0][i] = 0;
    rep(i, 1, n){
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        if(a[i] == 1 || a[i] == 3){
            /// can go to contest today
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
        }
        if(a[i] == 2 || a[i] == 3){
            /// can go to gym today
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
        }
    }
    cout<<n - max(dp[n][0], max(dp[n][1], dp[n][2]));
}
