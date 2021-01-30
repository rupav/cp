#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n;  /// Array size

ll t[2*N];

ll combine(ll a, ll b){
    // return max(a, b);
    // return a + b;
    return min(a, b);
}

ll init(){
    // return 0ll;
    // return 0ll;
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

int main(){
    int q;
    cin>>n>>q;
    initialize();

    for(int i=0; i<n; i++){
        cin>>t[i + n];
    }
    build();

    int l, r, c, val;
    while(q--){
        cin>>c;
        c--;
        if(!c){
            /// modify
            cin>>l>>val;
            l--;    /// to make 0-index
            modify(l, val);
        } else {
            /// query of sum;
            cin>>l>>r;
            l--, r--;
            cout<<query(l, r + 1)<<endl;
        }
    }

    return 0;
}


