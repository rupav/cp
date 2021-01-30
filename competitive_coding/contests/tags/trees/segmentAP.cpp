/// Arithmetic progression update on a segment
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

struct Node{
    int k;
    int d;
    int sm;
};

Node t[4 * N], lazy[4 * N];

/// build, update, query, lazy

void push(int tn, int tl, int tr){
    int sz = (tr - tl + 1)/2;

    t[2*tn].k += lazy[tn].k, t[2*tn + 1].k += lazy[tn].k + sz*lazy[tn].d;
    t[2*tn].d += lazy[tn].d, t[2*tn + 1].d += lazy[tn].d;

    t[2*tn].sm += lazy[tn].k*sz + lazy[tn].d*(sz)*(sz - 1)/2;
    t[2*tn + 1].sm += (lazy[tn].k + sz*lazy[tn].d)*sz + lazy[tn].d*(sz)*(sz - 1)/2;

    lazy[2*tn].k += lazy[tn].k, lazy[2*tn + 1].k += lazy[tn].k + sz*lazy[tn].d;
    lazy[2*tn].d += lazy[tn].d, lazy[2*tn + 1].d += lazy[tn].d;

    lazy[tn].k = lazy[tn].d = 0;
}

void build(int a[], int tn, int tl, int tr){
    if(tl == tr) {
        t[tn].k = 0;
        t[tn].d = 0;
        t[tn].sm = a[tl];
        lazy[tn].k = lazy[tn].d = 0;
        return;
    }

    int tm = (tl + tr)/2;
    build(a, 2*tn, tl, tm);
    build(a, 2*tn + 1, tm + 1, tr);

    t[tn].d = t[tn].k = 0;
    t[tn].sm = t[2*tn].sm + t[2*tn + 1].sm;
    lazy[tn].k = lazy[tn].d = 0;
}

void update(int tn, int tl, int tr, int l, int r, int k, int d){
    if(l > r) return;
    if(tl == l && tr == r){

        t[tn].k += k, t[tn].d += d;
        lazy[tn].k += k, lazy[tn].d += d;

        int sz = (tr - tl + 1);
        t[tn].sm += sz*k + d*(sz*(sz - 1))/2;

    } else {

        push(tn, tl, tr);
        int tm = (tl + tr)/2;
        update(2*tn, tl, tm, l, min(r, tm), k, d);
        update(2*tn + 1, tm + 1, tr, max(l, tm + 1), r, k + d*max(tm - l + 1, 0), d);

        t[tn].sm = t[2*tn].sm + t[2*tn + 1].sm;

    }
}

int query(int tn, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r) return t[tn].sm;

    push(tn, tl, tr);
    int tm = (tl + tr)/2;
    return query(2*tn, tl, tm, l, min(r, tm))
        +  query(2*tn + 1, tm+1, tr, max(l, tm + 1), r);
}

void solve(){
    int n, q, l, r, k, d, c;
    cin>>n>>q;
    int a[n];
    fr(i, n) cin>>a[i];
    build(a, 1, 0, n-1);
    while(q--){
        cin>>c;
        if(c == 1){
            /// update
            cin>>l>>r>>k>>d;
            l--, r--;
            update(1, 0, n-1, l, r, k, d);
        } else {
            /// query
            cin>>l>>r;
            l--, r--;
            cout<<query(1, 0, n-1, l, r)<<endl;
        }
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

