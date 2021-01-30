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

#define M 101

int MinAdjCost(int *arr, int n, int x){
    int dp[n+1][M];
    fr(j, M) dp[0][j] = 0;  /// initialization.

    rep(i, 1, n){
        fr(j, M){
            dp[i][j] = INT_MAX;
            rep(k, max(0, j-x), min(j+x, M-1)){
                dp[i][j] = min(dp[i-1][k], dp[i][j]);
            }
            dp[i][j] += abs(j - arr[i-1]);
        }
    }

    int ans = INT_MAX;
    fr(j, M) ans = min(ans, dp[n][j]);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    int n, x;
    while(t--){
        cin>>n>>x;
        int arr[n];
        fr(i, n) cin>>arr[i];
        cout<<MinAdjCost(arr, n, x)<<endl;
    }

    return 0;
}

