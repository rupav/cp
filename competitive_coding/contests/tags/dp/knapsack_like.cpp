/// given m pairs of integers, find if it is poosible
/// to take from each pair exactly 1 no. and the sum of those chosen m no.s is 'n'.

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


bool solve(){
    int n, m, x, y;
    cin>>n>>m;
    vector<pii> v;
    int mx;
    fr(i, m){
        cin>>x>>y;
        v.push_back({x, y});
        mx += max(x, y);
    }

    int s = mx;    /// max sum possible
    vector<vector<bool>> dp(m+1, vector<bool>(s + 1, false));
    /// dp[i][j] = whether sum j is possible with i components processed!
    dp[0][0] = 1;   /// taking no element sum is 0

    for(int i = 0; i < m; i++){
        for(int j = 0; j <= s - max(v[i].first, v[i].second); j++){
            if(dp[i][j]){
                dp[i+1][j + v[i].first] = dp[i+1][j + v[i].second] = 1;
            }
        }
    }

    cout<<"\t";
    rep(j, 0, s) cout<<j<<" ";
    cout<<endl;
    rep(i, 0, m){
        cout<<i<<"\t";
        rep(j, 0, s){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[m][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "Yes" : "No")<<endl;
    }

    return 0;
}

