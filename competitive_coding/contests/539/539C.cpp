#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
ll dp[1<<21][2];  /// dp[xor][i%2]: store no. of elements at i%2 indices(odd / even), which have same xor uptil that index i, as the current prefix xor sum.

int main(){
    int n;
    cin>>n;
    ll arr[n];

    ll prefix = 0;
    dp[0][0] = 1;   /// since we have found 1 element with xor prefixes sum till that equal to 0, and that is 0th prefix sum.
    ll count = 0;
    rep(i, 1, n){
        cin>>arr[i-1];
        prefix ^= arr[i-1];
        count += dp[prefix][i%2];
        dp[prefix][i%2] += 1;
    }
    cout<<count;

    return 0;
}
