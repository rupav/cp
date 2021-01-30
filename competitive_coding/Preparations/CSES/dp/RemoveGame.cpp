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

const int nax = 5005;
ll a[nax];
vector<vector<ll>> dp;
ll INIT = 1e18L + 5;

ll recurse(int st, int en){
    if(st > en) return 0ll;
    ll &z = dp[st][en];

    if(z != INIT) return z;
    ll lt = recurse(st + 1, en);
    ll rt = recurse(st, en - 1);
    return z = max(a[st] - lt, a[en] - rt);
}


void solve(){
    int n;
    cin>>n;
    dp.resize(n, vector<ll>(n, INIT));
    fr(i, n) cin>>a[i];
    ll diff = recurse(0, n-1);   /// X - Y
    ll tot = accumulate(a, a + n, 0ll);
    ll ans = (tot + diff)/2ll;
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

