#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int minAbsDiffPartition(int *arr, int n, int sum){
    bool dp[sum+1][n+1];
    fr(i, sum+1)
        fr(j, n+1)
            dp[i][j] = false;
    fr(j, n+1)
        dp[0][j] = true;
    for(int i=1; i<=sum; i++){
        for(int j=1; j<=n; j++){
            if(i-arr[j-1]>=0)
                dp[i][j] = dp[i][j-1] || dp[i - arr[j-1]][j-1];  /// at one time considering jth element, and in other not considering
            else
                dp[i][j] = dp[i][j-1];
        }
    }

    int ans = 0;
    rep(i, sum/2, sum){
        if(dp[i][n]){
            ans = abs(sum-2*i);
            break;
        }
    }
    return ans;
}

int main(){
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        int arr[n];
        int sum = 0;
        fr(i, n){
            cin>>arr[i];
            sum += arr[i];
        }
        cout<<minAbsDiffPartition(arr, n, sum)<<endl;
    }
    return 0;
}
