#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int findWays(string &s, int si, int en){
    if(en<-1)
        return 0;
    if(en == 0 || en==-1)
        return 1;
    if(((int)(s[en-1]-'0')==1) || ((int)(s[en-1] - '0')==2 && (int)(s[en]-'0')<=6)){
        return findWays(s, si, en-2) + findWays(s, si, en-1);
    } else {
        return findWays(s, si, en-1);
    }
}

int main(){
    string s;
    while(true){
        cin>>s;
        if(s=="0")
            break;
        // cout<<findWays(s, 0, s.size()-1)<<endl;
        int n = s.size();
        int dp[n+1];
        dp[0] = dp[1] = 1;
        int en;  /// for 1-base indexing
        rep(i, 2, n){
            en = i-1;
            if(((int)(s[en-1]-'0')==1) || ((int)(s[en-1] - '0')==2 && (int)(s[en]-'0')<=6)){
                dp[i] = dp[i-2];
                if((int)(s[en]-'0')!=0)
                    dp[i] += dp[i-1];
            } else if((int)(s[en]-'0')!=0) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = 0;  /// invalid case.s
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}

