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
    int n;
    cin>>n;
    char x;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;

    fr(i, n){
        fr(j, n){
            cin>>x;
            if(x == '.'){
                if(i + 1 < n) add_self(dp[i + 1][j], dp[i][j]);
                if(j + 1 < n) add_self(dp[i][j + 1], dp[i][j]);
            }
        }
    }

    cout<<((x == '.') ? dp[n - 1][n - 1] : 0);
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

