#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
const int N = 1e5;



struct data{
    int sum, pref, suff, ans;
};

data t[4*N];

data combine(data l, data r){
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, l.suff + r.sum);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

data make_data(int val){
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0, val);
    return res;
}

void build(int a[], int node, int tl, int tr){
    if(tl == tr) return void(t[node] = make_data(a[tl]));
    int tm = (tl + tr)>>1;
    build(a, 2*node, tl, tm);
    build(a, 2*node+1, tm+1, tr);
    t[node] = combine(t[2*node], t[2*node+1]);
}

void update(int node, int tl, int tr, int pos, int new_val){
    if(tl == tr) return void(t[node] = make_data(new_val));
    int tm = (tr + tl)>>1;
    if(pos <= tm) update(2*node, tl, tm, pos, new_val);
    else update(2*node+1, tm+1, tr, pos, new_val);
    t[node] = combine(t[2*node], t[2*node+1]);
}

data query(int node, int tl, int tr, int l, int r){
    if(l > r) return make_data(0);
    if(tl == l && tr == r) return t[node];
    int tm = (tl + tr)>>1;
    return combine(query(2*node, tl, tm, l, min(r, tm)),
                   query(2*node+1, tm+1, tr, max(l, tm+1), r));
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    build(a, 1, 0, n-1);
    int q, c;
    cin>>q;
    while(q--){
        cin>>c;
        if(c == 1){
            /// get max sum
            int l, r;
            cin>>l>>r;
            cout<<query(1, 0, n-1, l, r).ans<<endl;
        } else {
            /// update a[i] to new val
            int pos, val;
            cin>>pos>>val;
            update(1, 0, n-1, pos, val);
        }
    }
    return 0;
}
