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

int mat[1002][1002];
int dp1[1002][1002];
int dp2[1002][1002];
int dp3[1002][1002];
int dp4[1002][1002];

void solve(int n, int m){
    /// 1 based indexing
    rep(i, 0, n+1){
        rep(j, 0, m+1){
            dp1[i][j] = dp2[i][j] = dp3[i][j] = dp4[i][j] = 0;
        }
    }


    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp1[i][j] = mat[i][j] + max(dp1[i-1][j], dp1[i][j-1]);
        }
    }

    for(int i=n; i>=1; i--){
        for(int j=1; j<=m; j++){
            dp2[i][j] = mat[i][j] + max(dp2[i+1][j], dp2[i][j-1]);
        }
    }

    for(int i=n; i>=1; i--){
        for(int j=m; j>=1; j--){
            dp3[i][j] = mat[i][j] + max(dp3[i+1][j], dp3[i][j+1]);
        }
    }


    for(int i=1; i<=n; i++){
        for(int j=m; j>=1; j--){
            dp4[i][j] = mat[i][j] + max(dp4[i-1][j], dp4[i][j+1]);
        }
    }

    /// for every cell find the answer, if that cell is chosen as the meeting cell
    int ans = 0;
    for(int i=2; i<n; i++){
        for(int j=2; j<m; j++){
            /// lahub came from left, going right and larry come from bottom, and went up
            int temp = dp1[i][j-1] + dp3[i][j+1] + dp2[i+1][j] + dp4[i-1][j];
            ans = max(ans, temp);
            /// lahub came from up, went down, larry came from left, went right
            temp = dp1[i-1][j] + dp3[i+1][j] + dp2[i][j-1] + dp4[i][j+1];
            ans = max(ans, temp);
        }
    }

    cout<<ans;


}

int main(){
    int n, m;
    cin>>n>>m;
    rep(i, 1, n) rep(j, 1, m) cin>>mat[i][j];
    solve(n,  m);
    return 0;
}
