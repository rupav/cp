#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

void findWaysToAddUpToSum(int *arr, int n, int sum, int x){
    int dp[sum+1];
    fr(i, sum+1)
        dp[i] = 0;
    dp[0] = 1;
    fr(i, n){
        for(int j=sum; j>=arr[i]; j--){
            int t = arr[i];
            dp[j] += dp[j-t];
        }
    }
    fr(i, sum+1)
        cout<<dp[i]<<" ";
    /// now removing x;
    cout<<endl;
    rep(i, x, sum){
        dp[i] -= dp[i-x];
    }
    fr(i, sum+1)
        cout<<dp[i]<<" ";
}

int main(){
    int n;
    int s, x;
    cin>>n>>s>>x;
    int arr[n];
    fr(i, n)
        cin>>arr[i];
    findWaysToAddUpToSum(arr, n, s, x);
    return 0;
}

