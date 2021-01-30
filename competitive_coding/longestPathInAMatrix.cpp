#include<bits/stdc++.h>
using namespace std;

int matrixHelper(int i, int j, int n, int **mat, int **dp){
    if(i<0 || i>=n || j<0 || j>=n) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN;

    if(j < n-1 && (mat[i][j] + 1 == mat[i][j+1])){
        x = 1 + matrixHelper(i, j+1, n, mat, dp);
    }
    /// to be continued
}

int main() {

}
