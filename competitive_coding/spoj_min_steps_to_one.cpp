#include<bits/stdc++.h>
using namespace std;
#define LIM 20000000

int* bottomUp(){
    int *dp = new int[LIM];
    dp[0] = 0;
    dp[1] = 0;
    int subOne = INT_MAX, divTwo = INT_MAX, divThree = INT_MAX;
    int n = LIM;
    for(int i=2; i<n; i++){
        subOne = dp[i-1];
        if(i%2 == 0){
            divTwo = dp[i/2];
        }
        if(i%3 == 0){
            divThree = dp[i/3];
        }
        dp[i] = 1 + min(subOne, min(divTwo, divThree));
        subOne = INT_MAX;
        divTwo = INT_MAX;
        divThree = INT_MAX;
    }
    return dp;
}

int main() {
    int t;
    cin>>t;
    int i = 1;
    int n;
    int *arr = bottomUp();
    while( i<=t ) {
        cin>>n;
        cout<<"Case "<<i<<": "<<arr[n]<<endl;
        i++;
    }
    return 0;
}
