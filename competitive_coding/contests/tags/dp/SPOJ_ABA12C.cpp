#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int t;
    cin>>t;
    int n, k;
    while(t--){
        cin>>k>>n;
        int arr[n+1];
        fr(i, n)
            cin>>arr[i+1];
        /// sum has to be n, from 1, 2, .... n kg packets, with cost arr[i].
        /// cost has to be minimized.
        int dp[n+1];
        fr(i, n)
            dp[i+1] = INT_MAX;

        dp[0] = 0;  /// by choosing 0 element, so 0 cost.
        rep(i, 1, n){
            rep(j, 1, i){
                /// ith sum, checking each jth packet cost.
                if(arr[j]!=-1 && dp[i-j] != INT_MAX)
                    dp[i] = min(dp[i], dp[i-j] + arr[j]);
            }
        }
        if(dp[n] == INT_MAX)
            cout<<-1<<endl;
        else
            cout<<dp[n]<<endl;
    }

    return 0;
}

