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

int MinCost(string s, string t, int *c){
    /// cost are in c[0], and c[1] of deleting a character from string s & t respectively.
    int m = s.length();
    int n = t.length();
    int dp[m+1][n+1];  /// dp[i][j] stores minimum cost for strings of length i & j respectively.
    rep(i, 0, m) dp[i][0] = c[0]*i;
    rep(j, 0, n) dp[0][j] = c[1]*j;
    dp[0][0] = 0;

    rep(i, 1, m){
        rep(j, 1, n){
            if(s[i-1] == t[j-1]){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1] + c[1], dp[i-1][j] + c[0]));
            } else {
                dp[i][j] = min(dp[i-1][j-1] + c[0] + c[1], min(dp[i][j-1] + c[1], dp[i-1][j] + c[0]));
            }
        }
    }
    return dp[m][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    string s1, s2;
    int c[2];
    while(t--){
        fr(i, 2) cin>>c[i];
        cin>>s1>>s2;
        cout<<MinCost(s1, s2, c)<<endl;
    }

    return 0;
}
