#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


/// O(n^2) approach, similar to finding longest increasing subsequence.
ll countIncreasingSubsequences(int *arr, int n){
    int dp[n];
    dp[0] = 1;
    ll ans = 1;
    rep(i, 1, n-1){
        dp[i] = 1;
        fr(j, i){
            if(arr[j] < arr[i]){
                dp[i] += dp[j];
            }
        }
        ans += dp[i];
    }
    return ans;
}

/// O(n) approach, iff all elements are between 0 and 9, both included.
ll countIncreasingSubsequences_On(int *arr, int n){
    ll cnt[10] = {0};
    cnt[arr[0]] = 1;
    int dig;
    rep(i, 1, n-1){
        dig = arr[i];
        fr(j, dig){
            cnt[dig] += cnt[j];
        }
        cnt[dig] += 1;
    }
    ll ans = 0;
    fr(i, 10)
        ans += cnt[i];
    return ans;
}

int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int arr[n];
        fr(i, n)
            cin>>arr[i];
        cout<<countIncreasingSubsequences_On(arr, n)<<endl;
    }
    return 0;
}

