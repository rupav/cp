#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

void add_self(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}

int sub_mod(int a, int b){
    a -= b;
    if(a < 0) a += mod;
    return a;
}

const int nax = 3005;
int pref[nax] = {0};

/// O(n^2) approach
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    /// dp[i][j] - count of valid permutations for size i with last element as j
    dp[1][1] = 1;

    pref[1] = 1;

    for(int len  = 2; len <= n; ++len){
        char x = s[len - 2];

        for(int nxt = 1; nxt <= len; ++nxt){

            if(x == '<'){
                /// _ < _, and condn: nxt >= prev + 1
                add_self(dp[len][nxt], pref[nxt - 1]);

            } else {
                /// _ > _ and condn: nxt <= prev
                add_self(dp[len][nxt], sub_mod(pref[len - 1], pref[nxt - 1]));

            }
        }

        /// restore pref for next iteration, len + 1
        int s = 0;
        for(int j = 1; j <= len; j++){
            add_self(s, dp[len][j]);
            pref[j] = s;
        }
    }

    int res = 0;
    for(int j = 1; j <= n; ++j){
        add_self(res, dp[n][j]);
    }
    cout<<res;
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

