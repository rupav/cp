/// Find the smallest number greater or equal to a specified number. With Modification
#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
const int N = 1e5;

multiset<int> t[4*N];  /// max size of tree is O(nlogn) /// merge sort tree

void build(int a[], int node, int tl, int tr){
    if(tl == tr) return void(t[node].insert(a[tl]));
    int tm = (tl + tr)>>1;
    build(a, 2*node, tl, tm);
    build(a, 2*node+1, tm+1, tr);
    merge(t[2*node].begin(), t[2*node].end(),
          t[2*node+1].begin(), t[2*node+1].end(), inserter(t[node], t[node].end()));
}

int query(int node, int tl, int tr, int l, int r, int x){
    if(l > r) return INF;
    if(tl == l && tr == r){
        multiset<int>:: iterator lb = t[node].lower_bound(x);
        if(lb != t[node].end()) return *lb;
        return INF;
    }
    int tm = (tl + tr)>>1;
    return min(query(2*node, tl, tm, l, min(r, tm), x),
               query(2*node+1, tm+1, tr, max(l, tm+1), r, x));
}

void update(int a[], int node, int tl, int tr, int pos, int new_val){
    t[node].erase(t[node].find(a[pos]));
    t[node].insert(new_val);
    if(tl != tr){
        int tm = (tl + tr)>>1;
        if(pos <= tm) update(a, 2*node, tl, tm, pos, new_val);
        else update(a, 2*node+1, tm+1, tr, pos, new_val);
    } else a[pos] = new_val;
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
            ///
            int l, r, x;
            cin>>l>>r>>x;
            cout<<query(1, 0, n-1, l, r, x)<<endl;
        } else {
            /// With modification
            int pos, val;
            cin>>pos>>val;
            update(a, 1, 0, n-1, pos, val);
        }
    }
    return 0;
}

