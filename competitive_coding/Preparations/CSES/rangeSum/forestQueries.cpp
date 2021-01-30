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


void solve(){
    int n, q, x1, y1, x2, y2;
    cin>>n>>q;
    char z;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    rep(i, 1, n){
        rep(j, 1, n){
            cin>>z;
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            if(z == '*') dp[i][j]++;
        }
    }

    while(q--){
        cin>>x1>>y1>>x2>>y2;
        int cnt = dp[x2][y2];
        cnt += dp[x1 - 1][y1 - 1];
        cnt -= dp[x1 - 1][y2];
        cnt -= dp[x2][y1 - 1];
        cout<<cnt<<endl;
    }

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

