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

/// DP

void solve(){
    int n, m, x, y;
    cin>>n>>m>>x>>y;

    vector<int> dp(m + 1, 0);
    rep(i, 1, m){
        dp[i] = dp[i - 1] + x;
        if(i >= 2) dp[i] = min(dp[i], dp[i - 2] + y);
    }

    ll cost = 0ll;
    string s;
    int st, en, j, k, len;
    fr(i, n){
        cin>>s;
        j = 0;
        while(j < m){
            if(s[j] == '.'){
                k = j + 1;
                while(k < m && s[k] == '.') k++;
                len = k - j;
                cost += (ll) dp[len];

                j = k;
            } else j++;
        }
    }

    cout<<cost<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

