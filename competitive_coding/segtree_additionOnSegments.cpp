/// e.g. of range update -
/// query: type1: add value to all elements in the segment[l...r]; type2: get a[i]

#include<bits/stdc++.h>
using namespace std;

#define MAXN 10000
int t[MAXN];

void build(int node, int tl, int tr, int arr[]){
    if(tl == tr){
        t[node] = arr[tr];
    } else {
        int tm = (tl+tr)/2;
        build(2*node, tl, tm, arr);
        build(2*node+1, tm+1, tr, arr);
        t[node] = 0;  /// in this segment, we don't need to add anything yet to all elements!
    }
}

void update(int node, int tl, int tr, int l, int r, int add){
    if(l > r){
        return;
    }
    if(tl == l && tr == r){
        t[node] += add;
    } else {
        int tm = (tl+tr)/2;
        update(2*node, tl, tm, l ,min(tm, r), add);
        update(2*node+1, tm+1, tr, max(tm+1, l), r, add);
    }
}

int query(int node, int tl, int tr, int pos){
    if(tl == tr){
        return t[node];
    } else {
        int tm = (tl + tr)/2;
        if(pos <= tm){
            return t[node] + query(2*node, tl, tm, pos);
        } else {
            return t[node] + query(2*node+1, tm+1, tr, pos);
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    build(1, 0, n-1, arr);
    int q, x, y, add;
    while(true){
        cin>>q>>x;
        if(q == 0){
            /// update query
            cin>>y>>add;
            update(1, 0, n-1, x, y, add);
        } else if (q == 1) {
            cout<<query(1, 0, n-1, x)<<endl;
        } else {
            break;
        }
    }
    return 0;
}
