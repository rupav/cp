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

const int LIM = 100005;
ll dp[LIM];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.size();
    dp[0] = 0ll;
    dp[1] = 1ll;
    dp[2] = 2ll;

    rep(i, 3, LIM-1){
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    }

    if((s.find('w') != string::npos) || (s.find('m') != string::npos)){
       cout<<0;
       return 0;
    }

    ll ans = 1ll;
    for(int i=0; i<n;){
        if(s[i] == 'u' || s[i] == 'n'){
            int j = i+1;
            while(j<n && s[j] == s[i]) j++;
            ans = (ans*dp[j-i])%mod;
            i = j;
        } else {
            i++;
        }
    }
    cout<<ans;

    return 0;
}

