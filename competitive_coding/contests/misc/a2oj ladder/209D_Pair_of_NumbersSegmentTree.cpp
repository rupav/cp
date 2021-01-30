#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}


const int N = 3e5 + 5;
int n;

ll t[2 * N][2];

ll init(bool f){
    if(!f) return 0ll;
    return INT_MAX;
}

void initialize(bool f){
    for(int i=0; i<2*N; i++) t[i][f] = init(f);
}

ll combine(ll a, ll b, bool f){
    if(!f) return gcdll(a, b);
    return min(a, b);
}

void build(bool f){
    for(int i = n - 1; i > 0; --i) t[i][f] = combine(t[i<<1][f], t[i<<1|1][f], f);
}

void modify(int p, ll val, bool f){
    for(t[p += n][f] = val; p > 1; p >>= 1) t[p >> 1][f] = combine(t[p][f], t[p^1][f], f);
}

ll query(int l, int r, bool f){
    ll resl(init(f)), resr(init(f));
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1ll) resl = combine(t[l++][f], resl, f);
        if(r&1ll) resr = combine(resr, t[--r][f], f);
    }
    return combine(resl, resr, f);
}

void solve(){
    cin>>n;
    int a[n];

    initialize(0);
    initialize(1);

    fr(i, n) {
        cin>>a[i];
        t[n + i][0] = t[n + i][1] = a[i];
    }
    build(0);
    build(1);


    /// binary search over the maximum possible size r - l
    int m, l = 0, r = n - 1;
    bool f;
    int ans = 0;    /// min answer
    while(l <= r){
        m = l + (r - l)/2;
        /// gcd(segment) = min(segment) for all segments of length m + 1
        f = false;
        fr(i, n - m){
            if(query(i, i + m + 1, 0) == query(i, i + m + 1, 1)){
                f = true;
                break;
            }
        }

        if(!f){
            /// answer is less
            r = m - 1;
        } else {
            /// answer is atleast m
            ans = m;
            l = m + 1;
        }
    }

    vector<int> res;
    fr(i, n - ans){
        if(query(i, i + ans + 1, 0) == query(i, i + ans + 1, 1)){
            res.push_back(i + 1);
        }
    }

    cout<<res.size()<<" "<<ans<<endl;
    for(auto it: res) cout<<it<<" ";

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

