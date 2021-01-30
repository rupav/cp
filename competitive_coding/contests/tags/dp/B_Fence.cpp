#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;

int main(){
    int n, k;
    cin>>n>>k;
    ll a[n];
    fr(i, n) cin>>a[i];
    ll dp[n-k+1] = {0ll};
    fr(i, k){
        dp[0] += a[i];
    }
    rep(i, k, n-1){
        dp[i-k+1] = dp[i-k] - a[i-k] + a[i];
    }

    cout<<(min_element(dp, dp+n-k+1) - dp)+1;

    return 0;
}
