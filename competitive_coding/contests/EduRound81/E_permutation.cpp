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

const int N = 1e5 + 5;
ll bit[N];

void update(int i, ll upd){
    for(; i < N; i += i&(-i)) bit[i] += upd;
}

ll get(int i){
    ll sm = 0ll;
    for(; i > 0; i -= i&(-i)) sm += bit[i];
    return sm;
}

/// alternate question solved - make a seperation, and then maintain the size of both, and get the answer.
void solve(){
    int n;
    cin>>n;
    vector<ll> p(n + 1), a(n + 1), dp(n + 1, 0);
    rep(i, 1, n) cin>>p[i];
    rep(i, 1, n) cin>>a[i];
    map<int, bool> mp;

    ll mn = INT_MAX;
    rep(i, 1, n){
        ll &z = dp[i];
        z = dp[i - 1];
        if(i == p[i]){
            /// do nothing
            z += a[i];
        } else {
            if(mp[i]) z -= a[i];
            else z += a[i];

            if(p[i] > i){
                z += a[p[i]];
            } else {
                z -= a[p[i]];
            }

        }
        mp[p[i]] = 1;
        watch(dp[i]);
        if(i == p[i]) mn = min(mn, z - a[i]);
        else mn = min(mn, z);
        watch(mn);
    }

    cout<<mn;

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

