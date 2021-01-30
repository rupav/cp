/// Adding on segments, querying for maximum
#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
const int N = 1e5;

int t[4*N], lazy[4*N] = {0};

void push(int node){
    for(auto child: {2*node, 2*node + 1}){
        t[child] += lazy[node];
        lazy[child] += lazy[node];
    }
    lazy[node] = 0;
}

void build(int a[], int node, int tl, int tr){
    if(tl == tr) return void(t[node] = a[tl]);
    int tm = (tl + tr)>>1;
    build(a, 2*node, tl, tm);
    build(a, 2*node+1, tm+1, tr);
    t[node] = max(t[2*node], t[2*node+1]);
}

void update(int node, int tl, int tr, int l, int r, int add){
    if(l > r) return;
    if(tl == l && tr == r){
        t[node] += add;
        lazy[node] += add;  // it can be leaf node, i.e. tl = tr
    } else {
        push(node);
        int tm = (tl + tr)>>1;
        update(2*node, tl, tm, l, min(r, tm), add);
        update(2*node+1, tm+1, tr, max(l, tm+1), r, add);
        t[node] = max(t[2*node], t[2*node+1]);
    }
}

int query(int node, int tl, int tr, int l, int r){
    if(l > r) return -INF;
    if(tl == l && tr == r) return t[node];
    push(node);
    int tm = (tl + tr)>>1;
    return max(query(2*node, tl, tm, l, min(r, tm)),
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
            /// get max val
            int l, r;
            cin>>l>>r;
            cout<<query(1, 0, n-1, l, r)<<endl;
        } else {
            /// add a[i] to new val
            int l, r, add;
            cin>>l>>r>>add;
            update(1, 0, n-1, l, r, add);
        }
    }
    return 0;
}
