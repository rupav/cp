#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int t[2*N];

void build(){   /// build the tree
    for(int i = n-1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int val){    /// set value at pos p
    for(t[p += n] = val; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r){    /// sum of interval [l, r)
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1) res += t[l++];
        if(r&1) res += t[--r];
    }
    return res;
}

int main(){
    int l, r;
    cin>>n;
    for(int i=0; i<n; i++) cin>>*(t + n + i);
    build();
    int q;
    cin>>q;
    while(q--){
        cin>>l>>r;  /// find sum of interval [l, r)
        cout<<query(l, r)<<endl;
    }
    return 0;
}
