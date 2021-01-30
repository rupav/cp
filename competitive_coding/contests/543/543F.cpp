/// compress string
#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

string reverseS(string s){
    string r = "";
    for(int i=s.size()-1; i>=0; i--)
        r+=s[i];
    return r;
}

int main(){
    int n, a, b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int dp[n+1];  /// dp[i] is minimal cost to encode the prefix of s of length i.
    dp[0] = 0;
    rep(i, 1, n){
        dp[i] = 0;
        dp[i] = a+dp[i-1];  /// encode the single character, and pay for it, by a coins.
        /// first reverse s.substr(0, i) and then calculate z-array of it,
        /// then check min. cost for each z[k] > 0, there is a substring present as the prefix, with length z[k], thus can be encoded by paying b coins!
        string r = reverseS(s.substr(0, i));  /// since we need dp[i], i.e. string of length i, not i+1.
        /// now string r's first character is 's[i-1]', and thus any prefix matching it on z-array, will be useful for us.
        vector<int> z = constructZFunc(r);
        int m = r.size();
        rep(j, 1, m-1){
            if(z[j] && z[j] <= j){
                dp[i] = min(dp[i], b + dp[i-z[j]]);
            }
        }
    }
    cout<<dp[n];
    return 0;
}

