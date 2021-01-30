#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)

int main(){
    int n, a[3];
    cin>>n;
    fr(i, 3) cin>>a[i];
    int dp[n+1] = {-1};
    dp[0] = 0;
    rep(i, 1, n){
        int temp = 0;
        fr(j, 3){
            if(i >= a[j]){
                temp = (dp[i-a[j]] != -1) ? max(temp, dp[i-a[j]] + 1) : temp;
            }
        }
        dp[i] = (temp == 0) ? -1 : temp;
    }
    cout<<dp[n];
    return 0;
}
