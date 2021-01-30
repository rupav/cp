#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int cutSegments(int n, vector<int>& v){
    /// first remove duplicate elements.
    map<int, bool> mp;
    vector<int> mv;
    for(auto i: v){
        if(mp[i] != true)
            mv.push_back(i);
        mp[i] = true;
    }
    int dp[n+1];  /// dp[i] stores max segments to make it to 'i' from array elements.
    /// assuming 0 doesn't exist, in array elements, otherwise infinite solution!
    dp[0] = 0;
    rep(i, 1, n){
        dp[i] = -1;
        for(auto j: mv){
            if(j <= i && dp[i-j] != -1){
                dp[i] = max(dp[i], dp[i-j]+1);
            }
        }
    }
    return dp[n];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x, y, z;
        cin>>n>>x>>y>>z;
        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        cout<<cutSegments(n, v)<<endl;
    }
    return 0;
}
