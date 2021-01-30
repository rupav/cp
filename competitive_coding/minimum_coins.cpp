#include<bits/stdc++.h>
using namespace std;
#define LIM 100000

/// topDown
int minCoins(int *dp, int *coins, int n, int x) {

	if(dp[x]!=-1){
		return dp[x];
	}
	if(x == 0){
		return 0;
	}
	int res = INT_MAX;
	for(int i=0; i<n; i++){
		if(coins[i] <= x) {
			int subRes = 1 + minCoins(dp, coins, n, x - coins[i]);
			if(subRes < res){
				res = subRes;
			}
		}
	}
	return dp[x] = res;
}

/// bottomUp
int* minCoins2(int *coins, int n) {
    int *dp = new int[LIM];
    for(int i=0; i<LIM; i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for(int i=1; i<LIM; i++){
        for(int j=0; j<n; j++) {
            if(coins[j] <= i){
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    return dp;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	int x, n;
	while(t--) {
		cin>>x>>n;
		int *coins = new int[n];
		int *dp = new int[x+1];
		for(int i=0; i<=x; i++) {
			dp[i] = -1;
		}
		for(int i=0; i<n; i++) {
			cin>>coins[i];
		}

		// int res = minCoins(dp, coins, n, x);

		dp = minCoins2(coins, n);
		int res = dp[x];

		if(res == INT_MAX) {
			cout<<"No solution";
		} else {
			cout<<res;
		}
		cout<<endl;
	}
	return 0;
}
