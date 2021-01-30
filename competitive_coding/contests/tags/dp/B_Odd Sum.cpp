#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    int a[n];
    fr(i, n) cin>>a[i];
    int dp[n];
    memset(dp, 0, sizeof(dp));
    int i=0;
    int max_sum = 0;
    while(i<n && abs(a[i])%2 == 0){
        max_sum = max(max_sum, max_sum+a[i]);
        i++;
    }
    /// i is pointing at first index having odd no.
    a[i] += max_sum;  /// max_sum is gauanteed to be greater than zero

    int odd = a[i];
    int even = max_sum;
    rep(j, i+1, n-1){
        if(a[j]&1){
            dp[j] = a[j] + even;
            even = max(even, odd+a[j]);
            odd = max(odd, dp[j]);
        } else {
            dp[j] = a[j] + odd;
            even = max(even, a[j]+even);
            odd =max(odd, dp[j]);
        }
    }
    cout<<odd;
    return 0;
}
