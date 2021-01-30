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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

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

ll CountWays(int *arr, int n, int sum){
    ll dp[sum+1][n+1];
    memset(dp, 0, sizeof(dp));
    fr(j, n+1) dp[0][j] = 1ll;  /// initialization
    rep(i, 1, sum){
        rep(j, 1, n){
            if(i - arr[j-1] >= 0)
                dp[i][j] = dp[i][j-1] + dp[i-arr[j-1]][j-1];
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    fr(i, sum+1){
        fr(j, n+1){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[sum][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, sum;
    cin>>n>>sum;
    int arr[n];
    fr(i, n) cin>>arr[i];
    cout<<CountWays(arr, n, sum)<<endl;
    return 0;
}

