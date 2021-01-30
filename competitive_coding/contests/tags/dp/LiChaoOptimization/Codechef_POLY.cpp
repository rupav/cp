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
const ll inf = 1e18L + 5;
const int sz = 350;    /// >sqrt(1e5)

struct Func{
    ll a, b, c, d;
    void in(){
        cin>>d>>c>>b>>a;
    }
    ll val(ll x){
        if(a == inf) return inf;
        return a * x * x * x + b * x * x + c * x + d;
    }
};

const ll TMAX = 1e5 + 5;

Func t[4 * TMAX];

void add_func(Func nf, int tv = 1, int tl = sz + 1, int tr = TMAX){
    int tm = (tl + tr)/2;

    bool lef = nf.val(tl) < t[tv].val(tl);
    bool mid = nf.val(tm) < t[tv].val(tm);

    if(mid){
        swap(nf, t[tv]);
    }

    if(tr - tl == 1) return;
    if(mid != lef){
        /// first half contains intersection
        add_func(nf, 2 * tv, tl, tm);
    } else {
        add_func(nf, 2 * tv + 1, tm, tr);
    }
}

ll get_min(ll x, int tv = 1, int tl = sz + 1, int tr = TMAX){
    int tm = (tl + tr)/2;
    ll mn = t[tv].val(x);
    if(tr - tl == 1) return mn;
    if(x < tm) return mn = min(mn, get_min(x, 2 * tv, tl, tm));
    else return mn = min(mn, get_min(x, 2 * tv + 1, tm, tr));
}

void solve(){

    int n, q, x;
    cin>>n;
    vector<Func> funcs(n);
    fr(i, n) funcs[i].in();

    rep(i, 0, 4 * TMAX -  1) t[i] = {inf, 0ll, 0ll, 0ll};

    ll cache[sz + 1];   /// stores the results i.e. min for these many points, brute force

    rep(i, 0, sz){
        cache[i] = inf;
        for(Func it: funcs){
            cache[i] = min(cache[i], it.val(i));
        }
    }

    for(auto it: funcs){
        add_func(it);
    }

    cin>>q;
    fr(i, q){
        cin>>x;
        if(x <= sz) cout<<cache[x]<<endl;
        else cout<<get_min(x)<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

