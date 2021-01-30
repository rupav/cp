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
const int N = 100005;
ll dp[N] = {0};
ll pSum[N] = {0};

void solve(int k){
    dp[0] = 1;
    rep(i, 1, N-1){
        dp[i] = dp[i-1];
        if(i>=k)
        dp[i] = (dp[i]%mod + dp[i-k]%mod)%mod;
    }
    pSum[0] = 0;
    rep(i, 1, N-1){
        pSum[i] = (pSum[i-1]%mod + dp[i]%mod)%mod;
    }
}

int main(){
    int t, k, a, b;
    cin>>t>>k;
    solve(k);
    while(t--){
        cin>>a>>b;
        cout<<(mod + pSum[b] - pSum[a-1])%mod<<endl;
    }
    return 0;
}
