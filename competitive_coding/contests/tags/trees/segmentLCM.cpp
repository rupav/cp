/// LCM of elements in a range
#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
const int N = 1e5;

int t[4*N];

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a%b);
}

int combine(int a, int b){
    return ((a*b)/gcd(a, b));
}

void build(int a[], int node, int tl, int tr){
    if(tl == tr) return void(t[node] = a[tl]);
    int tm = (tl + tr)>>1;
    build(a, 2*node, tl, tm);
    build(a, 2*node+1, tm+1, tr);
    t[node] = combine(t[2*node], t[2*node+1]);
}

int get_lcm(int node, int tl, int tr, int l, int r){
    if(l > r) return 1;
    if(tl == l && tr == r) return t[node];
    int tm = (tl + tr)>>1;
    return combine(get_lcm(2*node, tl, tm, l, min(r, tm)),
                   get_lcm(2*node+1, tm +1, tr, max(l, tm+1), r));
}

void update(int node, int tl, int tr, int pos, int new_val){
    if(tl == tr) return void(t[node] = new_val);
    int tm = (tl + tr)>>1;
    if(pos <= tm) update(2*node, tl, tm, pos, new_val);
    else update(2*node+1, tm+1, tr, pos, new_val);
    t[node] = combine(t[2*node], t[2*node+1]);
}

void print(int node, int tl, int tr){
    if(tl == tr) {
        cout<<node<<": "<<t[node]<<endl;
        return;
    }
    int tm = (tl + tr)>>1;
    print(2*node, tl, tm);
    print(2*node+1, tm+1, tr);
    cout<<node<<": "<<t[node]<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    build(a, 1, 0, n-1);
    int q, c;
    cin>>q;
    // print(1, 0, n-1);
    while(q--){
        cin>>c;
        if(c == 1){
            /// get gcd
            int l, r;
            cin>>l>>r;
            cout<<get_lcm(1, 0, n-1, l, r)<<endl;
        } else {
            /// update a[i] to new val
            int pos, val;
            cin>>pos>>val;
            update(1, 0, n-1, pos, val);
        }
    }
    return 0;
}

