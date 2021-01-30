/// finding and printing maximum no. of non-overlapping blocks/segments for a given sum - DP method. : O(n) method!
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
    int arr[n+1];
    rep(i, 1, n) cin>>arr[i];
    arr[0] = 0;
    int pr[n+1] = {0};
    rep(i, 1, n){
        pr[i] = pr[i-1] + arr[i];
    }

    /// finding continuous blocks for a given sum, x
    int x;
    cin>>x;
    int dp[n+1] = {0};
    int l[n+1] = {0};
    rep(i, 1, n){
        dp[i] = dp[i-1];
        l[i] = -1;
        rep(j, 0, i-1){
            if(dp[i] < dp[j] + (pr[i] - pr[j] == x)){
                dp[i] = dp[j] + (pr[i] - pr[j] == x);
                l[i] = j+1;
            }
        }
    }

    cout<<dp[n]<<endl;
    /// printing block now, with the help of l array.
    int k = n;
    set<pii> blocks;
    while(k > 0){
        if(l[k] == -1){
            k--;
            continue;
        }
        blocks.insert({l[k], k});
        k = l[k] - 1;  /// next, non overlapping index.
    }

    for(auto it: blocks){
        cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}

