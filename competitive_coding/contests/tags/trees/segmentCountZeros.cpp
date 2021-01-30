/// Counting the number of zeros, searching for the k-th zero
#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
const int N = 1e5;

using pii = pair<int, int>;
int t[4*N];  /// to store count of zeros on each segment

void build(int a[], int node, int tl, int tr){
    if(tl == tr) return void(t[node] = (!a[tl]));
    int tm = (tl + tr)>>1;
    build(a, 2*node, tl, tm);
    build(a, 2*node+1, tm+1, tr);
    t[node] = t[2*node] + t[2*node+1];
}

int count_zero(int node, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r) return t[node];
    int tm = (tl + tr)>>1;
    return count_zero(2*node, tl, tm, l, min(r, tm)) +
            count_zero(2*node+1, tm+1, tr, max(l, tm+1), r);
}

int find_kth(int node, int tl, int tr, int k){
    if(k > t[node]) return -1;
    if(tl == tr) return tl;
    int tm = (tl + tr)>>1;
    if(t[2*node] >= k){
        return find_kth(2*node, tl, tm, k);
    } else {
        return find_kth(2*node+1, tm+1, tr, k - t[2*node]);
    }
}

void update(int node, int tl, int tr, int pos, int new_val){
    if(tl == tr) return void(t[node] = (!new_val));
    int tm = (tl + tr)>>1;
    if(pos <= tm) update(2*node, tl, tm, pos, new_val);
    else update(2*node+1, tm+1, tr, pos, new_val);
    t[node] = t[2*node] + t[2*node+1];
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
            /// get count of zeros
            int l, r;
            cin>>l>>r;
            cout<<count_zero(1, 0, n-1, l, r)<<endl;
        } else if (c == 2) {
            /// find kth zero
            int k;
            cin>>k;
            cout<<find_kth(1, 0, n-1, k)<<endl;
        } else {
            /// update a[i] to new val
            int pos, val;
            cin>>pos>>val;
            update(1, 0, n-1, pos, val);
        }
    }
    return 0;
}
