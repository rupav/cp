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

int main(){
    string s;
    int n;
    cin>>n;
    cin>>s;
    vector<char> v;
    /// compress the string
    int i=0;
    while(i<n){
        int j = i+1;
        while(s[j] == s[i])++j;
        v.push_back(s[i]);
        i=j;
    }
    n = v.size();
    int dp[n][n];  /// min. no. of steps required to solve for s[i...j]
    memset(dp, 0, sizeof(dp));
    fr(i, n) dp[i][i] = 1;
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(j == i+1){
                dp[i][j] = 2;  /// gauranteed, since adjacent elements cant be equal in compressed array!
                continue;
            }
            dp[i][j] = dp[i+1][j] + 1;
            for(int k=i+2; k<=j; k++){
                if(v[k] == v[i])
                    dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]);
            }
        }
    }
    cout<<dp[0][n-1];
}
