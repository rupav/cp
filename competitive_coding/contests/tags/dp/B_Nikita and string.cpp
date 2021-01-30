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

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    int dp[n];
    fr(i, n) dp[i] = 1;
    /// O(n^2) approach
    fr(i, n){
        int ans = 1;
        if(s[i] == 'a'){
            for(int j=i-1; j>=0; j--){
                ans = max(ans, dp[j] + 1);
            }
            dp[i] = ans;
        } else {
            /// either remove all 'a' till last b (left of this b) or remove all b left of it
            int j;
            for(j=i-1; j>=0; j--){
                if(s[j] == 'b') break;
            }
            int cnt = 0;
            for(int k=0; k<i; k++) cnt += (s[k] == 'a');  /// deleting all previous 'b's
            if(j<0){
                /// no 'b' found before
                dp[i] = cnt+1;
            } else {
                dp[i] = max(dp[i], dp[j] + 1);  /// deleting in between 'a's
                dp[i] = max(cnt+1, dp[i]);
            }
        }
    }
    // for(auto it: dp) cout<<it<<" ";
    cout<<*max_element(dp, dp+n);
}

void solve_linear(){
    string s;
    cin>>s;
    int n = s.size();
    /// cnt[3], 3 variables for count of 'a...a', (a)b....b, (a)b....ba...a sequences till now
    int cnt[3] = {0};
    int prev[3] = {0}; /// previous states
    fr(i, n){
        cnt[0] = prev[0] + (s[i] == 'a');
        cnt[1] = max(prev[0], prev[1]) + (s[i] == 'b');
        cnt[2] = max(prev[1], prev[2]) + (s[i] == 'a');
        fr(j, 3) prev[j] = cnt[j];
    }
    cout<<*max_element(cnt, cnt+3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // solve();
    solve_linear();

    return 0;
}
