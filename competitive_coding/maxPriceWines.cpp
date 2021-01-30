#include<bits/stdc++.h>
using namespace std;
#define LIM 10000

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

int** initialize2darray(int rows, int cols, int value = INT_MIN){
    int **arr = new int*[rows];
    for(int i=0; i<rows; i++){
        arr[i] = new int[cols];
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++) {
            arr[i][j] = value;
        }
    }
    return arr;
}

int _cost(int cost, int i, int j, int n){
    return cost*(n - (j - i + 1) + 1);
}

int maxPriceWines_bottomUp(int *arr, int n) {
    int** dp = initialize2darray(n ,n, -1);
    int k=0;
    while(k < n){
        for(int i=0; i+k<n; i++){
            if(k == 0){
                dp[i][i] = _cost(arr[i], i, i, n);
            } else {
                dp[i][i+k] = max(_cost(arr[i], i, i+k, n) + dp[i+1][i+k], _cost(arr[i+k], i, i+k, n) + dp[i][i+k-1]);
            }
        }
        k++;
    }
    cout<<"DP array built is "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];
}

int maxPriceWines(int **dp, int *arr, int si, int ei, int year){
    if(si > ei){
        return 0;
    }
    if (dp[si][ei] != -1){
        return dp[si][ei];
    }
    dp[si][ei] = max(arr[si]*year + maxPriceWines(dp, arr, si+1, ei, year+1), arr[ei]*year + maxPriceWines(dp, arr, si, ei-1, year+1));
    return dp[si][ei];
}

int main() {
    int t;
    cout<<"enter number of cases"<<endl;
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter number of wines"<<endl;
        cin>>n;
        int *arr = new int[n];
        cout<<"enter cost of each wine"<<endl;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        /// int **dp = initialize2darray(n, n, -1);

        cout<<endl<<"Max profit is: "<<endl;
        /// cout<<maxPriceWines(dp, arr, 0, n-1, 1);
        cout<<maxPriceWines_bottomUp(arr, n);
    }

    return 0;
}
