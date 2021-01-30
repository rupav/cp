#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
typedef long long ll;

int main(){
    int n;
    cin>>n;
    int a[n], dp[n];
    fr(i, n) dp[i] = 1;
    fr(i, n) cin>>a[i];
    for(int i=1; i<n; i++){
        dp[i] += (a[i] > a[i-1])*(dp[i-1]);
    }
    cout<<*max_element(dp, dp+n);
    return 0;
}
