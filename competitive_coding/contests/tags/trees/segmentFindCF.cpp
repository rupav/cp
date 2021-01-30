#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

const int N = 1e5;

int t[4*N];

/// Searching for an array (non negative integers) prefix with a given amount or greater
void build(int a[], int node, int tl, int tr){
    if(tl == tr) return void(t[node] = a[tl]);
    int tm = (tl + tr)>>1;
    build(a, 2*node, tl, tm);
    build(a, 2*node+1, tm+1, tr);
    t[node] = t[2*node] + t[2*node+1];
}

void update(int node, int tl, int tr, int pos, int new_val){
    if(tl == tr) return void(t[node] = new_val);
    int tm = (tl + tr)>>1;
    if(pos <= tm){
        update(2*node, tl, tm, pos, new_val);
    } else update(2*node+1, tm+1, tr, pos, new_val);
    t[node] = t[2*node] + t[2*node+1];
}

int find_prefix(int node, int tl, int tr, int sum){
    if(sum > t[node]) return -1;
    if(tl == tr) return tl;
    int tm = (tr + tl)>>1;
    if(sum <= t[2*node]) return find_prefix(2*node, tl, tm, sum);
    return find_prefix(2*node+1, tm+1, tr, sum - t[2*node]);
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
            int sum;
            cin>>sum;
            cout<<find_prefix(1, 0, n-1, sum)<<endl;
        } else {
            /// update a[i] to new val
            int pos, val;
            cin>>pos>>val;
            update(1, 0, n-1, pos, val);
        }
    }
    return 0;
}
