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

void max_self(int &a, int b){
    a = max(a, b);
}

void solve(){
    string s, t;
    cin>>s>>t;
    int n(s.size()), m(t.size());

    vector<vector<int>> lcs(n + 1, vector<int>(m + 1, 0));
    /// lcs[i][j] = length of longest common subsequence with pref. of length i & j considered of string s & t resp.

    rep(i, 0, n - 1){
        rep(j, 0, m - 1){
            if(s[i] == t[j]){
                max_self(lcs[i + 1][j + 1], lcs[i][j] + 1);
            }
            max_self(lcs[i][j + 1], lcs[i][j] + 0);
            max_self(lcs[i + 1][j], lcs[i][j] + 0);
            }

    }

    int ans = 0;
    rep(i, 1, n){
        rep(j, 1, m){
            cout<<lcs[i][j]<<" ";
            max_self(ans, lcs[i][j]);
        }
        cout<<endl;
    }

    ans = max({lcs[n-1][m], lcs[n][m], lcs[n][m - 1]});

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

