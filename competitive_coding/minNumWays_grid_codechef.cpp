#include <iostream>
using namespace std;
#define MOD 1000000007

int numWays(int rows, int cols, int **dp){
	// index-1 based array!
	if(dp[1][1] == -1){
		return 0;
	}
	for(int i=1; i<=rows; i++){
		if( dp[i][1] == -1 ){
			break;
		}
		dp[i][1] = 1;
	}
	for(int j=1; j<=cols; j++){
		if( dp[1][j] == -1 ){
			break;
		}
		dp[1][j] = 1;
	}
	for(int i=2; i<=rows; i++){
		for(int j=2; j<=cols; j++){
			if(dp[i][j] == -1){
				continue;
			}
			if(dp[i-1][j] != -1){
				dp[i][j] = dp[i-1][j]%MOD;
			}
			if(dp[i][j-1] != -1){
				dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
			}
		}
	}
	if( dp[rows][cols] == -1 ){
        return 0;
	}
	return dp[rows][cols];
}

int main() {
	// your code goes here
	int m, n, p, bl_x, bl_y;
	cin>>m>>n>>p;
	int **dp = new int*[m+1];
	for(int i=1; i<=m; i++){
		dp[i] = new int[n+1];
		for(int j=1; j<=n; j++){
			dp[i][j] = 0;  // initialize all cells with 0
		}
	}
	while(p--){
		cin>>bl_x>>bl_y;
		dp[bl_x][bl_y] = -1; // initialize blocked cells with -1
	}
	cout<<numWays(m, n, dp);
	return 0;
}
