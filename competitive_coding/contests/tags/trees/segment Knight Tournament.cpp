#include<bits/stdc++.h>
using namespace std;

const int LIM = 3e5+1;
int t[4*LIM];
bool marked[4*LIM] = {false};

void push(int node){
    if(marked[node]){
        t[2*node] = t[2*node+1] = t[node];
        marked[2*node] = marked[2*node+1] = true;
        marked[node] = false;
    }
}

void build(int a[], int node, int tl, int tr){
    if(tl == tr) return void(t[node] = a[tl]);
    int tm = (tl + tr)>>1;
    build(a, 2*node, tl, tm);
    build(a, 2*node+1, tm+1, tr);
}

void update(int node, int tl, int tr, int l, int r, int new_val){
    if (l > r) return;
    if(tl == l && tr == r){
        t[node] = new_val;
        marked[node] = true;
    } else {
        push(node);
        int tm = (tl + tr)>>1;
        update(2*node, tl, tm, l, min(r, tm), new_val);
        update(2*node+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int get(int node, int tl, int tr, int pos){
    if(tl == tr) return t[node];
    if(marked[node]) return t[node];    // do not make delayed updates
    push(node);
    int tm = (tl + tr)>>1;
    if(pos <= tm){
        return get(2*node, tl, tm, pos);
    } else return get(2*node+1, tm+1, tr, pos);
}

struct Info{
    int l, r, winner;
};

int main(){
    int n, m;
    cin>>n>>m;

    vector<Info> v(m);
    for(int i=0; i<m; i++){
        cin>>v[i].l>>v[i].r>>v[i].winner;
    }

    reverse(v.begin(), v.end());

    for(auto it: v){
        update(1, 1, n, it.l, it.winner - 1, it.winner);
        update(1, 1, n, it.winner+1, it.r, it.winner);
    }

    for(int i=1; i<=n; i++){
        cout<<get(1, 1, n, i)<<" ";
    }

    return 0;
}
