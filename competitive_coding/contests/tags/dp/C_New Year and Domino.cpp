#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

int dp[501][501][3];  /// dp[i][j][0]: counts the dominoes possible from (1, 1) to (i, j)
char mat[501][501];

int n, m, x1, x2, y1, y2;

int main(){
     cin>>n>>m;
     char x;
     rep(i, 0, n) mat[i][0] = '#';
     rep(i, 0, m) mat[0][i] = '#';

     rep(i, 1, n){
        rep(j, 1, m){
            cin>>x;
            dp[i][j][0] = dp[i-1][j][0] + dp[i][j-1][0] - dp[i-1][j-1][0];
            dp[i][j][1] = dp[i-1][j][1];
            dp[i][j][2] = dp[i][j-1][2];
            if(x == '.'){
                dp[i][j][0] += (mat[i-1][j] == '.') + (mat[i][j-1] == '.');  /// make 2 connections as well!
                dp[i][j][1] += (mat[i][j-1] == '.');
                dp[i][j][2] += (mat[i-1][j] == '.');
            }
            mat[i][j] = x;
        }
     }

     /*
     fr(k, 3){
     rep(i, 1, n){
        rep(j, 1, m){
            cout<<dp[i][j][k]<<" ";
        }
        cout<<endl;
     }
     cout<<endl<<endl;
     }
     */

     int q;
     cin>>q;
     while(q--){
        cin>>x1>>y1>>x2>>y2;
        int sum1 = dp[x1-1][y1-1][0];
        int sum2 = dp[x1-1][y2][0] - sum1;
        int sum3 = dp[x2][y1-1][0] - sum1;
        int sum = dp[x2][y2][0];
        sum -= (sum1 + sum2 + sum3);
        sum -= (dp[x2][y1][1] - dp[x1][y1][1]);
        sum -= (dp[x1][y2][2] - dp[x1][y1][2]);
        if(mat[x1][y1] == '.'){
            sum -= (mat[x1-1][y1] ==  '.');
            sum -= (mat[x1][y1-1] ==  '.');
        }
        cout<<sum<<endl;
     }

}
