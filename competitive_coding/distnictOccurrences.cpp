#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

/// find distinct occurrences of t string in s, example: if s="geeksforgeeks" and t="ge", return 6
/// O(n^m) approach
int distinctOccurrences(string s, string t){
    int n = s.size();
    int m = t.size();
    int dp[n+1][m+1];
    fr(j, m+1)
        dp[0][j] = 0;
    fr(i, n+1)
        dp[i][0] = 1;
    rep(i, 1, n){
        rep(j, 1, m){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i-1][j];  /// ith and jth chacters didn't match, so find result in s[0...i-1] for t[0...i].
            }
        }
    }
    return dp[n][m];
}

int main(){
    /// submitted on geeks already!
    string s, t;
    cin>>s>>t;
    cout<<distinctOccurrences(s, t)<<endl;
    return 0;
}

