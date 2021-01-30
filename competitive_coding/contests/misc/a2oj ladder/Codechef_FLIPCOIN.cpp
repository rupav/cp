/// lazy propogation using seg tree
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



const int N = 1e5 + 5;
int t[4 * N] = {0}, lazy[4 * N] = {0};
int a[N] = {0};

void build(int node, int tl, int tr){
    if(tl == tr) return void(t[node] = a[tl]);
    int tm = (tl + tr)/2;
    build(2*node, tl, tm);
    build(2*node + 1, tm + 1, tr);
    t[node] = t[2*node + 1] + t[2*node];
}



void push(int node, int tl, int tr, int tm){
    int &flips = lazy[node];
    t[2*node] = (flips&1ll) ? (tm - tl + 1 - t[2*node]) : t[2*node];
    t[2*node + 1] = (flips&1ll) ? (tr - tm - t[2*node + 1]) : t[2*node + 1];
    lazy[2*node] += flips;
    lazy[2*node + 1] += flips;
    flips = 0;
}

/// Flip all coins in the range l-r
void update(int node, int tl, int tr, int l, int r){
    if(l > r) return;
    if(tl == l && tr == r){
        t[node] = r - l + 1 - t[node];  /// flip
        lazy[node]++;
    } else {
        int tm = (tl + tr)/2;
        push(node, tl, tr, tm);
        update(2*node, tl, tm, l, min(tm, r));
        update(2*node + 1, tm+1, tr, max(l, tm+1), r);

        t[node] = t[2*node] + t[2*node+1];
    }
}

/// count set bits
int query(int node, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r){
        return t[node];
    }
    int tm = (tl + tr)/2;
    push(node, tl, tr, tm);
    return query(2*node, tl, tm, l, min(tm, r)) + query(2*node + 1, tm + 1, tr, max(l, tm+1), r);
}

void solve(){
    int n, q, c, l, r;
    cin>>n>>q;
    build(1, 0, n-1);   /// already build with all 0's

    while(q--){
        cin>>c;
        if(!c){
            cin>>l>>r;
            update(1, 0, n-1, l, r);
        } else {
            cin>>l>>r;
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

