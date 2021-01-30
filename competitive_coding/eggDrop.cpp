#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;

/// n eggs, and k-floors: finding optimal xth floor for first egg to drop!
int eggDrop(int n, int k){
    int **dp = new int*[n+1];
    fr(i, n+1) dp[i] = new int[k+1];
    /// dp[i][j] is the minimal attempts given i eggs and j consecutive floors (it doesn't matter their order in the actual building), to find the critical floor.

    fr(j, k+1){
        dp[0][j] = 0;
        dp[1][j] = j;
    }

    rep(i, 1, n){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    rep(i, 2, n){
        rep(j, 2, k){
            dp[i][j] = INT_MAX;
            int *alias = &dp[i][j];
            rep(x, 1, j){
                int temp = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                if(temp < *alias){
                    *alias = temp;
                }
            }
        }
    }

    return dp[n][k];

}

int main()
{
        int t,n,k;
        cin>>t;
        while(t--) {
            cin>>n>>k;
            cout<<eggDrop(n,k)<<endl;
        }
	return 0;
}
