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

/// min. no. of partitions such that all substrings are palindrome
int PalindromePartitions(string s){
    int n = s.length();
    bool P[n][n];
    // initialization
    fr(i, n){
        fr(j, n) P[i][j] = false;
        P[i][i] = true;
    }
    for(int i=n-2; i>=0; i--){
        rep(j, i+1, n-1){
            if(j-i+1 == 2){
                P[i][j] = s[i] == s[j];
            } else {
                P[i][j] = (s[i] == s[j]) && (P[i+1][j-1]);
            }
        }
    }
    int dp[n] = {0};  /// dp[i] stores minimum palindrome partitions for s[0...i]
    rep(i, 1, n-1){
        if(P[0][i]) dp[i] = 0;
        else {
            dp[i] = i;  /// max value possible.
            rep(j, 0, i-1){
                if(P[j+1][i])
                    dp[i] = min(dp[i], dp[j]+1);
            }
        }
    }
    return dp[n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        cout<<PalindromePartitions(s)<<endl;
    }
    return 0;
}

