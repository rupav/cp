/// https://codeforces.com/problemset/problem/455/A

#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int maxE = INT_MIN;
    unordered_map<int, int> mp;

    fr(i, n){
        cin>>arr[i];
        maxE = max(maxE, arr[i]);
        mp[arr[i]] ++;
    }

    ll dp[maxE+1];

    dp[0] = 0;
    dp[1] = mp[1];

    rep(i, 2, maxE){
        dp[i] = max(1ll*dp[i-1], dp[i-2] + 1ll*mp[i]*i);
    }

    cout<<dp[maxE];

    return 0;
}

