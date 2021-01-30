#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int N;
    cin>>N;
    ll dp[12]; /// max no. of digits
    memset(dp, -1ll, sizeof(dp));
    int n = N;
    dp[0] = n%10;
    n /= 10;
    int i=1;
    while(n){
        int curr = n%10;
        if(curr == 0)
            dp[i] = 0;
        else {
            ll temp = pow(9ll, 1ll*i);
            if(curr == 1)
                dp[i] = max(dp[i-1]*1ll*curr, temp);
            else
                dp[i] = max(dp[i-1]*1ll*curr, 1ll*(curr-1)*temp);
        }
        n/=10;
        i++;
    }
    cout<<dp[i-1];
    return 0;
}

