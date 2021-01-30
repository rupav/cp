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

ll dp[101][101];
ll dp_w[101][101];

int main(){
    int n, k, d;
    cin>>n>>k>>d;
    fr(j, k+1) dp[0][j] = 1ll;
    rep(i, 1, n){
        rep(j, 1, k){
            dp[i][j] = 0ll;
            rep(l, 1, min(i, j)){
                dp[i][j] = (dp[i][j]%mod + dp[i-l][j]%mod)%mod;
            }
        }
    }

    fr(j, k+1) dp_w[0][j] = 1ll;
    rep(i, 1, n){
        rep(j, 1, k){
            dp_w[i][j] = 0ll;
            rep(l, 1, min(d-1, min(i, j))){
                dp_w[i][j] = (dp_w[i][j]%mod + dp_w[i-l][j]%mod)%mod;
            }
        }
    }

    cout<<(mod + dp[n][k] - dp_w[n][k])%mod<<endl;
    return 0;
}
