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

struct Block{
    int w, s, x;
    bool operator<(const Block& a){
        return w + s < a.w + a.s;
    }
};

vector<Block> v;

vector<vector<ll>> dp;

ll recurse(int st, int n, ll w){
    if(st == n) return 0ll;
    ll &z = dp[st][w];
    if(~z) return z;
    z = recurse(st + 1, n, w);
    if(w > (ll) v[st].s) return z;

    /// 2 cases, either we pick this block or not, and we recurse for other options!
    return z = max(z, recurse(st + 1, n, w + (ll) v[st].w) + (ll) v[st].x);
}

void max_self(ll &a, ll b){
    a = max(a, b);
}

void solve(){
    int n, w, s, x;
    cin>>n;
    v.resize(n);
    ll mxw = 0ll;
    fr(i, n){
        cin>>w>>s>>x;
        v[i] = {w, s, x};
        mxw += w;
    }

    sort(v.begin(), v.end());

    /*
    dp.resize(n, vector<ll>(mxw + 1ll, -1));
    /// dp[i][j] = max. value/score of the tower formed if we have j weights so far, and has to consider elements starting from i.

    recurse(0, n, 0);
    cout<<dp[0][0];
    */

    ll mxs = v.back().w + v.back().s;
    /// doing it like knapsack problem
    vector<ll> dp(mxs + 1ll, 0ll);
    /// dp[i] - max score with weight not exceeding i

    /// Time complexity after sorting is O(n*(s + w))
    for(Block b: v){
        for(ll weight_already = min((ll) b.s, (ll) mxs - (ll) b.w); weight_already >=0; weight_already--){
            max_self(dp[weight_already + (ll) b.w], dp[weight_already] + (ll) b.x);
        }
    }

    ll ans = 0;
    for(ll i = 0; i <= mxs; ++i) max_self(ans, dp[i]);

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
