#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)

int lcs( char *str1, char *str2, int m, int n ) {
    int **dp = new int*[m+1];
    for(int i=0; i<=m; i++){
        dp[i] = new int[n+1];
    }
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout<<dp[i][j]<<" ";
        }
    }
    return dp[m][n];
}

int main(){
    int t, m, n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        char *str1 = new char[m];
        char *str2 = new char[n];
        for(int i=0; i<m; i++){
            cin>>str1[i];
        }
        for(int i=0; i<n; i++){
            cin>>str2[i];
        }
        cout<<lcs(str1, str2, m, n)<<endl;
    }
    return 0;
}
