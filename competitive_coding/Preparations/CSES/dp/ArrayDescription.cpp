#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void add_self(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}

void solve(){
    int n, m, x;
    cin>>n>>m;

    vector<int> dp(m + 1, 0); /// dp[i] = no. of arrays for prefix considered so far ends with i value
    vector<int> tmp(m + 1, 0);

    fr(i, n){
        cin>>x;
        if(i == 0){
            if(x == 0) dp.assign(m + 1, 1);
            else dp[x] = 1;
            continue;
        }

        if(x == 0){
            tmp.assign(m + 1, 0);
            rep(i, 1, m) {
                if(i - 1 >= 1) add_self(tmp[i], dp[i - 1]);
                if(i + 1 <= m) add_self(tmp[i], dp[i + 1]);
                add_self(tmp[i], dp[i]);
            }
            dp = tmp;
        } else {
            int t = 0;
            if(x - 1 >= 1) add_self(t, dp[x - 1]);
            if(x + 1 <= m) add_self(t, dp[x + 1]);
            add_self(t, dp[x]);
            dp.assign(m + 1, 0);
            dp[x] = t;
        }
    }

    int ans = 0;
    rep(i, 1, m) add_self(ans, dp[i]);
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

