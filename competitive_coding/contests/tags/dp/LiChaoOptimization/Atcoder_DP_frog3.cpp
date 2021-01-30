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

struct line{
    ll m, c;
    ll val(ll x){
        return m * x + c;
    }
    ll intersectX(line b){
        return (b.c - c) / (m - b.m);
    }
};

const int N = 1e6 + 5;

line t[4 * N];

void add_line(line nl, int tv = 1, int tl = 0, int tr = N){
    int tm = (tl + tr)/2;
    bool lef = nl.val(tl) < t[tv].val(tl);
    bool mid = nl.val(tm) < t[tv].val(tm);

    if(mid){
        /// new line is min. for half without intersection
        swap(nl, t[tv]);
    }

    if(tr - tl == 1) return;
    if(mid != lef){
        /// [tl, tm) contains the intersection
        add_line(nl, 2 * tv, tl, tm);
    } else {
        /// [tm, tr) contains the intersection
        add_line(nl, 2 * tv + 1, tm, tr);
    }
}

ll get_min(ll x, int tv = 1, int tl = 0, int tr = N){
    int tm = (tl + tr)/2;
    ll mn = t[tv].val(x);
    if(tr - tl == 1) return mn;
    if(x < tm){
        return mn = min(mn, get_min(x, 2 * tv, tl, tm));
    } else {
        return mn = min(mn, get_min(x, 2 * tv + 1, tm, tr));
    }
}

vector<ll> h;

void solve(){
    ll n, c, x;
    cin>>n>>c;
    h.resize(n);
    fr(i, n) {
        cin>>h[i];
    }

    // fr(i, 4 * N) t[i] = {0ll, 0ll};

    /// dp[i] = c + min(dp[j] + sq(h[i] - h[j])); where j < i
    /// dp[i] = c + sq(h[i]) + min(-2h[j] * h[i] + sq(h[j]) + dp[j]);
    /// m = - 2h[j], c = sq(h[j]) + dp[j]
    /// segment tree is built on the query points, i.e. h[i]

    ll best = 0ll;
    line l = {-2ll * h[0], 0ll + sq(h[0])};
    add_line(l);
    rep(i, 1, n - 1){
        ll z = get_min(h[i]);
        best = c + sq(h[i]) + z;
        l = {-2ll * h[i], best + sq(h[i])};
        add_line(l);
    }

    cout<<best;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll tc = 1;
    //  cin>>t;
    while(tc--){
        solve();
    }

    return 0;
}

