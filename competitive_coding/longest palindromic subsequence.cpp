#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int LongestPalindromicSubsequence(string s){
    int n = s.length();
    int dp[n][n];  /// dp[i][j] stores the longest palindrome subsequence length for string s[i...j]
    // initialization
    fr(i, n){
        dp[i][i] = 1;
        fr(j, n){
            if(i != j) dp[i][j] = 0;
        }
    }
    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            int *dum = &dp[i][j];
            if(j-i+1 == 2){
                *dum = 1 + (s[i] == s[j]);
            } else {
                if(s[i] == s[j]) *dum = 2 + dp[i+1][j-1];
                else *dum = max(dp[i][j-1], dp[i+1][j]);
            }
        }
    }
    return dp[0][n-1];
}

int main(){

    string s;
    cin>>s;
    int n = s.size();
    int **dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[n];
        for(int j=0; j<n; j++){
            if(i == j){
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(j-i+1 == 2){
                if(s[i] == s[j])
                    dp[i][j] = 2;
                else
                    dp[i][j] = 1;
            } else if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i+1][j-1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }

        }
    }
    cout<<LongestPalindromicSubsequence(s)<<endl;
    cout<<"Longest Palindromic subsequence length is "<<dp[0][n-1]<<endl;
    return 0;

}


