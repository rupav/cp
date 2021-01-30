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

#define INF INT_MAX

void min_self(int &a, int b){
    a = min(a, b);
}

void solve(){
    int n, m;
    cin>>n>>m;

    /// min. no. of moves to cut i X j rectangle into squares - try every possible cut, and update dp
    /// n^2 * m + n * m^2 time complexity.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == j){
                dp[i][i] = 0;
            } else {
                for(int k = 1; k < j; k++){
                    /// vertical cuts
                    min_self(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }

                for(int k = 1; k < i; k++){
                    /// horizontal cuts
                    min_self(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
            }
        }
    }

    cout<<dp[n][m];
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


