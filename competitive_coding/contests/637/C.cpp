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

const int N = 2e5 + 5;
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

bool solve(){
    int x;
    cin>>n;

    int p[n+2];
    int val[n+2];
    set<int> prev;
    set<int> nxt;
    int pos[n+1];

    rep(i, 1, n) {
        cin>>x;

        t[n + i - 1] = 0;   /// all are 0 in starting

        pos[x] = i;
        val[i] = 0;
    }

    build();

    prev.insert(0);
    nxt.insert(n+1);
    val[0] = val[n+1] = 1;
    val[n+1] = n + 1;

    repn(i, n, 1){
        x = pos[i];

        auto lb = prev.upper_bound(-x);
        auto rb = nxt.upper_bound(x);

        val[x] = (x + *lb); /// no. of prev zeros
        val[*rb] -= val[x];
        /// update segment tree

        // watch(x);
        // watch(*rb);
        // watch(*lb);

        modify(x - 1, val[x]);
        if(*rb != n+1){
            modify(*rb - 1, val[*rb]);
        }

        // watch(query(0, n));
        // rep(i, 1, n) cout<<val[i]<<" ";
        // cout<<endl;

        if(query(0, n) > val[x]) return false;

        prev.insert(-x);
        nxt.insert(x);
    }

    return true;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll tc = 1;
    initialize();
    cin>>tc;
    while(tc--){
        cout<<(solve() ? "YES" : "NO")<<endl;
    }

    return 0;
}

