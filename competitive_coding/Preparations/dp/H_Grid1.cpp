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
int mod = 1e9+7;

const int nax = 1001;
char grid[nax][nax];

void add_self(int &a, int b){
    a = a + b;
    if(a >= mod) a -= mod;
}

void solve(){
    int h, w;
    cin>>h>>w;
    vector<vector<int>> dp(h, vector<int>(w, 0));
    fr(i, h) fr(j, w) cin>>grid[i][j];

    dp[0][0] = 1;
    for(int row = 0; row < h; row++){
        for(int col = 0; col < w; col++){
            for(auto r2: {row, row+1}){
                int c2 = col;
                if(r2 == row){
                    c2 = col+1;
                }
                if(r2 < h && c2 < w && grid[r2][c2] == '.'){
                    add_self(dp[r2][c2], dp[row][col]);
                }

            }
        }
    }

    cout<<dp[h-1][w-1];

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

