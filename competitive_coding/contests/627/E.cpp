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


void solve(){
    int n, h, l, r;
    cin>>n>>h>>l>>r;
    int a[n+1];
    rep(i, 1, n) cin>>a[i];
    int dp[n+1][h+1];   /// till array i, going to sleep at j, maximum result
    rep(i, 0, n) rep(j, 0, h) dp[i][j] = -1;
    map<int, int> mp;
    rep(i, l, r) mp[i] = true;
    dp[0][0] = 0;

    int h1, h2, t1, t2;
    rep(i, 1, n){
        fr(j, h){
            if(~dp[i-1][j]){
                h1 = (a[i] + j)%h;
                h2 = (a[i] - 1 + j)%h;
                t1 = mp[h1] ? 1 : 0;
                t2 = mp[h2] ? 1 : 0;
                dp[i][h1] = max(dp[i][h1], dp[i-1][j] + t1);
                dp[i][h2] = max(dp[i][h2], dp[i-1][j] + t2);
            }
        }
    }

    int ans = 0;
    fr(j, h) ans = max(ans, dp[n][j]);
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

