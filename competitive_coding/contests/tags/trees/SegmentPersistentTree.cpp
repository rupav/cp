/// Preserving the history of its values (Persistent Segment Tree)
#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
const int N = 1e5;


struct Vertex{
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {};
    Vertex(Vertex* l, Vertex *r) : l(l), r(r), sum(0) {
        if(l) sum += l->sum;
        if(r) sum += r->sum;
    }
};

Vertex* build(int a[], int tl, int tr){
    if(tl == tr) return new Vertex(a[tl]);
    int tm = (tl + tr)>>1;
    return new Vertex(build(a, tl, tm), build(a, tm+1,  tr));
}

int get_sum(Vertex *node, int tl, int tr, int l, int r){
    if(l > r)return 0;
    if(tl == l && tr == r) return node->sum;
    int tm = (tl + tr)>>1;
    return get_sum(node->l, tl, tm, l, min(r, tm)) + get_sum(node->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex *node, int tl, int tr, int pos, int new_val){
    if(tl == tr) return new Vertex(new_val);
    int tm = (tl + tr)>>1;
    if(pos <= tm) return new Vertex(update(node->l, tl, tm, pos, new_val), node->r);
    else return new Vertex(node->l, update(node->r, tm+1, tr, pos, new_val));
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    vector<Vertex*> v;
    Vertex* root = build(a, 0, n-1);
    v.push_back(root);
    int q, c;
    cin>>q;
    while(q--){
        cin>>c;
        if(c == 1){
            // update
            int pos, val;
            cin>>pos>>val;
            int s = v.size();
            v.push_back(update(v[s-1], 0, n-1, pos, val));
        } else {
            // return sum
            int l, r, version;
            cin>>version>>l>>r;  /// version is 0 based-indexing
            cout<<get_sum(v[version], 0, n-1, l, r)<<endl;
        }
    }
    return 0;
}
