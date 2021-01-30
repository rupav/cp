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
    int arr[n+1] = {0};
    rep(i, 1, n){
        cin>>arr[i];
    }

    map<int, vector<pii>> mp;
    int sum = 0;
    for(int r=1; r<=n; r++){
        /// store smallest blocks first.
        sum = 0;
        for(int l=r; l>0; l--){
            sum += arr[l];
            mp[sum].push_back({l, r});
        }
    }

    int pr[n+1] = {0};
    rep(i, 1, n){
        pr[i] = pr[i-1] + arr[i];
    }

    set<pii> ans;
    int maxBlocks = 0;
    sum = 0;
    /// O(n^4) approach, since possible sums are of quadratic order, and for each, we are using dp method, thus taking quadratic too.
    /// whereas in dp, for each sum, we were directly picking up block, sorted on value of 'r', while making the map mp, thus linear, therefore total: O(n^3).
    /// that's why this solution is acceptable for F1, not on F2 prob. For F2, we have to apply greedy approach.
    for(auto it: mp){
        /// finding max. no. of continuous blocks for a given sum, x
        int x = it.first;
        int dp[n+1] = {0};
        rep(i, 1, n){
            dp[i] = dp[i-1];
            rep(j, 0, i-1){
                if(dp[i] < dp[j] + (pr[i] - pr[j] == x)){
                    dp[i] = dp[j] + (pr[i] - pr[j] == x);
                }
            }
        }

        if(dp[n] > maxBlocks){
            sum = x;
            maxBlocks = dp[n];
        }
    }

    int x = sum;

    int dp[n+1] = {0};
    int l[n+1];
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

    cout<<blocks.size()<<endl;
    for(auto it: blocks){
        cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}
