#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int n;  /// Array size

vector<set<ll> > t(2 * N);

void combine(set<ll> &m, set<ll>& a, set<ll>& b){
    merge(a.begin(), a.end(), b.begin(), b.end(), inserter(m, m.end()));
}

void build(){
    for(int i = n - 1; i > 0; --i) combine(t[i], t[i<<1], t[i<<1|1]);
}


/// for range [l, r)
int query(int l, int r){
    set<ll> res;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1ll) combine(res, t[l++], res);
        if(r&1ll) combine(res, res, t[--r]);
    }
    return res.size();
}

int main(){
    int q;
    cin>>n>>q;
    int x;

    for(int i=0; i<n; i++){
        cin>>x;
        t[i + n].insert(x);
    }
    build();

    int l, r, c, val;
    while(q--){
        // cin>>c;
        c = 1;
        if(!c){
            /// modify
            cin>>l>>val;
            l--;    /// to make 0-index
            // modify(l, val);
        } else {
            /// query of sum;
            cin>>l>>r;
            l--, r--;
            cout<<query(l, r + 1)<<endl;
        }
    }

    return 0;
}

