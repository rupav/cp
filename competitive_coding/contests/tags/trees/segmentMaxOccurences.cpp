/// Finding the maximum and the number of times it appears
#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
const int N = 1e5;


using pii = pair<int, int>;
pii t[4*N];

pii combine(pii a, pii b){
    if(a.first > b.first) return a;
    if(b.first > a.first) return b;
    return make_pair(a.first, a.second + b.second);
}

void build(int a[], int node, int tl, int tr){
    if(tl == tr) return void(t[node] = make_pair(a[tl], 1));
    int tm = (tl + tr)>>1;
    build(a, 2*node, tl, tm);
    build(a, 2*node+1, tm+1, tr);
    t[node] = combine(t[2*node], t[2*node+1]);
}

pii get_max(int node, int tl, int tr, int l, int r){
    if(l > r) return make_pair(-INF, 0);
    if(tl == l && tr == r) return t[node];
    int tm = (tl + tr)>>1;
    return combine(get_max(2*node, tl, tm, l, min(r, tm)),
                   get_max(2*node+1, tm+1, tr, max(l, tm+1), r));
}

void update(int node, int tl, int tr, int pos, int new_val){
    if(tl == tr) return void(t[node] = make_pair(new_val, 1));
    int tm = (tl + tr)>>1;
    if(pos <= tm) update(2*node, tl, tm, pos, new_val);
    else update(2*node+1, tm+1, tr, pos, new_val);
    t[node] = combine(t[2*node], t[2*node+1]);
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
            /// get max, and occurences
            int l, r;
            cin>>l>>r;
            pii res = get_max(1, 0, n-1, l, r);
            cout<<res.first<<" "<<res.second<<endl;
        } else {
            /// update a[i] to new val
            int pos, val;
            cin>>pos>>val;
            update(1, 0, n-1, pos, val);
        }
    }
    return 0;
}
