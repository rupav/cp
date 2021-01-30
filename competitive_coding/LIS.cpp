#include<bits/stdc++.h>
#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, si, en) for(int i=si; i<=en; i++)
using namespace std;

int findLIS(int *arr, int n){
    int dp[n];
    dp[0] = 1;
    rep(i, 1, n-1){
        dp[i] = 1;
        fr(j, i){
            if(arr[j] <= arr[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    return *max_element(dp, dp+n);
}

int findLDS(int *arr, int n){
    int dp[n];
    dp[0] = 1;
    rep(i, 1, n-1){
        dp[i] = 1;
        fr(j, i){
            if(arr[j] >= arr[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    return *max_element(dp, dp+n);
}

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int *dp = new int[n];
        int *ind = new int[n];
        for(int i=0; i<n; i++){
            dp[i] = 1;
            ind[i] = i;
        }
        for(int i=1; i<n; i++){
            /// bottom up approach
            for(int j=0; j<i; j++){
                if(arr[j] <= arr[i]){
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        ind[i] = j;
                    }
                }
            }
        }
        int max_ = dp[0];
        int last_ind = 0;
        for(int i=0; i<n; i++){
            if(dp[i] > max_){
                max_ = dp[i];
                last_ind = i;
            }
        }
        cout<<findLIS(arr, n)<<endl;
        cout<<max_<<endl;
        /// print lcs elements in reverse order!
        cout<<arr[last_ind]<<" ";
        while(ind[last_ind] != last_ind){
            cout<<arr[ind[last_ind]]<<" ";
            last_ind = ind[last_ind];
        }
    }
    return 0;
}
