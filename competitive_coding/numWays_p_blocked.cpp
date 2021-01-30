#include<bits/stdc++.h>
using namespace std;
#define MAX_ROWS 100000
#define MAX_COLS 100000

int minWays(int **dp, int rows, int cols){
    if(dp[0][0] == -1){
        return -1;
    }
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(i == 0 && j == 0) {

            } else if (i == 0) {

            } else if (j == 0) {

            }
        }
    }
}

int main() {
    int **dp = new int[MAX_ROWS];
    for(int i=0; i<MAX_ROWS; i++) {
        dp[i] = new int[MAX_COLS];
    }
    return 0;
}
