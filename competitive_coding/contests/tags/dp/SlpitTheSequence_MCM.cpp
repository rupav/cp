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

/// given an array of n integers, you have to maximize reward by doing k splits. Each split gives a reward of product of sums of left and right bounded subarray
vector<vector<ll>> dp;
vector<ll> a;
vector<ll> pref;

ll recurse(int st, int n, int k, ll psum){
    ll &z = dp[st][k];
    if(~z) return z;
    if(!k) return z = 0ll;
    ll p1, p2;
    z = 0ll;
    for(int i=st+1; i <= n - k; ++i){
        p1 = pref[i - 1] - psum;
        ll temp = recurse(i, n, k - 1, p1 + psum);
        p2 = pref[n - 1] - pref[i - 1];
        z = max(z, temp + p1*p2);
    }
    return z;
}

void solve(){
    int n, k;
    cin>>n>>k;
    a.resize(n);
    pref.resize(n, 0);
    ll sum = 0ll;
    fr(i, n) {
        cin>>a[i];
        sum += a[i];
        pref[i] = sum;
    }

    /// order of the splits doesn't matter, associativity property holds!
    dp.resize(n, vector<ll>(k + 1, -1));

    ll res = recurse(0, n, k, 0ll);
    cout<<res;
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

