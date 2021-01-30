#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, pair<int, int>> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

template <typename T>
void max_self(T &a, T b){
    a = max(a, b);
}

void solve(){
    string s, t;
    cin>>s>>t;
    int n(s.size()), m(t.size());

    /// find longest common subsequence of s and t and print the subsequence
    /// pis<int, pii> dp[i][j] stores lcs length till s[i-1], t[j-1] as first element
    /// and stores the second element as the pair indices, from it came from
    vector<vector<pii>> dp(n+1, vector<pii>(m+1, {-1, {0, 0}}));
    dp[0][0] = {0, {0, 0}};
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(s[i] == t[j]){
                max_self(dp[i+1][j+1], make_pair(dp[i][j].first + 1, make_pair(i, j)));
            }
            max_self(dp[i+1][j], make_pair(dp[i][j].first + 0, make_pair(i, j)));
            max_self(dp[i][j+1], make_pair(dp[i][j].first + 0, make_pair(i, j)));
        }
    }


    pii ans = {0, {0, 0}};
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            max_self(ans, make_pair(dp[i][j].first, make_pair(i, j)));
        }
    }

    string z;
    while(ans.second.first && ans.second.second){
        int i = ans.second.first;
        int j = ans.second.second;

        pair<int, int> previous(dp[i][j].second);

        if(previous == make_pair(i - 1, j - 1)){
            z += s[i-1];    /// s[i - 1] = t[j-1]
        }

        ans.second = previous;
    }

    reverse(z.begin(), z.end());
    cout<<z;
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

