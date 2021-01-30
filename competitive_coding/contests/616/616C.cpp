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
#define int unsigned int

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

const int N = 3505;
int dp[N][N];
int a[N];
int n, m, k;

int solve(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    int turn = n - (j - i);
    int &z = dp[i][j];
    if(turn == m) return z = max(a[i], a[j]);
    if(turn <= k) return z = max(solve(i+1, j), solve(i, j-1));
    return  z = min(solve(i+1, j), solve(i, j-1));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        fr(i, n+1) fr(j, n+1) dp[i][j] = -1;
        k = min(k, m-1);
        fr(i, n) cin>>a[i];

        cout<<solve(0, n-1)<<endl;
    }

    return 0;
}
