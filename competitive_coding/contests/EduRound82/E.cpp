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



bool check(string &s, string &a, string &b){

    int l[3] = {s.size(), a.size(), b.size()};

    /// dp[i][j][k] - if s[0...i-1] contains non-intersecting a[0...j-1] & b[0...k-1] as subsequences
    vector<vector<vector<bool>>> dp(l[0]+1, vector<vector<bool>>(l[1]+1, vector<bool>(l[2]+1, 0)));
    dp[0][0][0] = 1;

    rep(i, 0, l[0] - 1){
        rep(j, 0, l[1]){
            rep(k, 0, l[2]){
                if(j < l[1])
                    dp[i + 1][j + 1][k] = dp[i + 1][j + 1][k] || ((s[i] == a[j]) && dp[i][j][k]);
                if(k < l[2])
                    dp[i + 1][j][k + 1] = dp[i + 1][j][k + 1] || ((s[i] == b[k]) && dp[i][j][k]);
                dp[i + 1][j][k] = dp[i+1][j][k] || dp[i][j][k];
            }
        }
    }

    return dp[l[0]][l[1]][l[2]];
}


vector<vector<int>> nxt;
/// nxt[i][j] - stores the next occurence of j, >= i

void fill_(string &s){
    int n = s.size();
    nxt.assign(n + 1, vector<int>(26, INT_MAX));

    repn(i, n - 1, 0){
        int x = s[i] - 'a';
        nxt[i] = nxt[i + 1];
        nxt[i][x] = i;
    }
}

void min_self(int &a, int b){
    a = min(a, b);
}

bool check_(string &s, string &a, string &b){
    int l[3] = {s.size(), a.size(), b.size()};

    /// dp[i][j] = min. length of s, for which there exists a[0...i-1] & b[0...j-1] exists as non-intersecting subsequence in s[0...val-1]
    vector<vector<int>> dp(l[1] + 1, vector<int>(l[2] + 1, INT_MAX));
    dp[0][0] = 0;
    int x;

    rep(i, 0, l[1]){
        rep(j, 0, l[2]){
            x = dp[i][j];
            if(x > l[0]) continue;

            if(i < l[1] && nxt[x][a[i] - 'a'] < INT_MAX)
                min_self(dp[i + 1][j], nxt[x][a[i] - 'a'] + 1);

            if(j < l[2] && nxt[x][b[j] - 'a'] < INT_MAX)
                min_self(dp[i][j + 1], nxt[x][b[j] - 'a'] + 1);
        }
    }

    int &z = dp[l[1]][l[2]];
    return (z < INT_MAX);
}

bool solve(){
    string s, t;
    cin>>s>>t;
    int n(s.size()), m(t.size());

    fill_(s);

    bool f = false;

    string a = "", b = t;
    fr(i, m){
        a = t.substr(0, i);
        b = t.substr(i, string::npos);
        f = f || check_(s, a, b);
    }

    return f;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "YES": "NO")<<endl;
    }

    return 0;
}
