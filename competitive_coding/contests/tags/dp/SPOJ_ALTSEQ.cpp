#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n;
    cin>>n;
    int arr[n];
    fr(i, n)
        cin>>arr[i];
    int dp[n];  /// dp[i] stores length of longest alternating subsequence from 0 to i indices.
    dp[0] = 1;
    int j;
    int sign;
    int ans = 1;
    rep(i, 1, n-1){
        dp[i] = 1;
        sign = arr[i]>0 ? 1 : -1;
        fr(j, i){
            if(((arr[j]*sign) < 0) && abs(arr[j]) < abs(arr[i])){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}

