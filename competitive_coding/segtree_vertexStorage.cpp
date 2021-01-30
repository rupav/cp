/// saving the entire subarray in the vertex -
/// Ques: Find the smallest number greater or equal to a specified number. With modification queries.
#include<bits/stdc++.h>
using namespace std;

/// store multisets on each vertex, merging of two child nodes, take O(log^2n) for merging two Red Black trees
#define MAXN 10000
multiset<int> t[4*MAXN];

void build(int arr[], int node, int tl, int tr){
    if(tl == tr){
        multiset<int> ms;
        ms.insert(arr[tl]);
        t[node] = ms;
    } else {
        int tm = (tl+tr)/2;
        build(arr, 2*node, tl, tm);
        build(arr, 2*node+1, tm+1, tr);
        merge(t[2*node].begin(), t[2*node].end(), t[2*node+1].begin(), t[2*node+1].end(), inserter(t[node], t[node].begin()));
    }
}

#define INF INT_MAX
int query(int node, int tl, int tr, int l, int r, int x){
    if( l > r ){
        return INF;
    }
    if(tl == l && tr == r){
        multiset<int>::iterator it = lower_bound(t[node].begin(), t[node].end(), x);
        if(it != t[node].end()){
            return *it;
        }
        return INF;
    }
    int tm = (tl + tr)/2;
    return min(
               query(2*node, tl, tm, l, min(r, tm), x),
               query(2*node+1, tm+1, tr, max(r, tm+1), r, x)
            );
}

void update(int node, int tl, int tr, int pos, int val, int arr[]){
    t[node].erase(t[node].find(arr[pos]));
    t[node].insert(val);
    if(tl == tr){
        arr[pos] = val;
    } else {
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(2*node, tl, tm, pos, val, arr);
        } else {
            update(2*node+1, tm+1, tr, pos, val, arr);
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    build(arr, 1, 0, n-1);
    int q, x, y, target;

    while(true){
        cin>>q>>x>>y;
        if(q == 0){
            /// update xth with y
            update(1, 0, n-1, x, y, arr);
        } else if (q == 1){
            cin>>target;
            int sum = query(1, 0, n-1, x, y, target);
            cout<<sum<<endl;
        } else {
            break;
        }
    }

    return 0;
}
