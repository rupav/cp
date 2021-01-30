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
int n;  /// Array size

ll t[2*N];

ll combine(ll a, ll b){
    return max(a, b);
    return a + b;
    return min(a, b);
}

ll init(){
    return 0ll;
    return 0ll;
    return INT_MAX;
}

void initialize(){
    for(int i=0; i<2*N; i++) t[i] = init();
}

void build(){
    for(int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}

void modify(int p, ll val){
    for(t[p += n] = val; p > 1; p >>= 1) t[p>>1] = combine(t[p], t[p^1]);
}

/// for range [l, r)
ll query(int l, int r){
    ll resl(init()), resr(init());
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1ll) resl = combine(t[l++], resl);
        if(r&1ll) resr = combine(resr, t[--r]);
    }
    return combine(resl, resr);
}

void solve(){

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
