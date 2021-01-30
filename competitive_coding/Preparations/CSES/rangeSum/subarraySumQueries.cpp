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

const int N = 2e5 + 5;
int n;  /// Array size

struct Node{
    ll pref, suff, sum, mx;

    void combine(Node& a, Node& b){
        if(a.sum == inf){
            mx = b.mx;
            suff = b.suff;
            sum = b.sum;
            pref = b.pref;
            return;
        }
        mx = max({a.suff + b.pref, a.mx, b.mx});
        pref = max(a.pref, a.sum + b.pref);
        suff = max(b.suff, a.suff + b.sum);
        sum = a.sum + b.sum;
    }

    void init(ll val){
        pref = suff = sum = mx = val;
    }

};

Node t[2 * N];

void build(){
    for(int i = n - 1; i > 0; --i) t[i].combine(t[i<<1], t[i<<1|1]);
}

void modify(int p, ll val){
    p += n;
    t[p].init(val);
    for(; p > 1; p >>= 1) t[p>>1].combine(t[p], t[p^1]);
}

/// for range [l, r)
ll query(int l, int r){
    // ll res = 0ll;
    Node res;
    res.init(inf);
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1ll) res.combine(res, t[l++]);
        if(r&1ll) res.combine(res, t[--r]);
    }
    return res.mx;
}

void print(){
    cout<<"----------------------"<<endl;
    rep(i, 1, 2 * n - 1){
        cout<<i<<endl<<t[i].sum<<" "<<t[i].mx<<" "<<t[i].pref<<" "<<t[i].suff<<endl;
    }
    cout<<"----------------------"<<endl;
}


void solve(){
    int q, x, l;
    cin>>n>>q;
    fr(i, n){
        cin>>x;
        t[i + n].init(x);
    }
    build();

    fr(i, q){
        cin>>l>>x;
        l--;
        modify(l, x);
        // print();
        cout<<query(0, n)<<endl;
    }

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

