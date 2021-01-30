#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000
// int t[4*MAXN];

class SegTreeSum{
private:
    int n;
    int *t;
public:
    SegTreeSum(int n){
        this->n = n;
        t = new int[4*n+1];
    }
    bool check(int x, int y);
    int average(int x, int y);
    void build(int arr[], int tl, int tr, int node);
    int getSum(int node, int tl, int tr, int l, int r);
    void update(int node, int tl, int tr, int pos, int val);
};

bool SegTreeSum::check(int x, int y){
    if(x < 0 || x >= this->n) return false;
    if(y<0 || y >= this->n) return false;
    return true;
}

int SegTreeSum::average(int x, int y){
    return (x+y)/2;
}

void SegTreeSum::build(int arr[], int tl, int tr, int node){
    if(tl == tr) t[node] = arr[tl];
    else {
        int tm = this->average(tl, tr);
        build(arr, tl, tm, 2*node);
        build(arr, tm+1, tr, 2*node+1);
        t[node] = t[2*node] + t[2*node+1];
    }
}

int SegTreeSum::getSum(int node, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r) return t[node];
    int tm = this->average(tl, tr);
    return (getSum(2*node, tl, tm, l, min(r, tm)) + getSum(2*node+1, tm+1, tr, max(l, tm+1), r));
}

void SegTreeSum::update(int node, int tl, int tr, int pos, int val){
    if(tl == tr) t[node] = val;
    else {
        int tm = average(tl, tr);
        if(pos <= tm){
            update(2*node, tl, tm, pos, val);
        } else {
            update(2*node+1, tm+1, tl, pos, val);
        }
        t[node] = t[2*node] + t[2*node+1];
    }
    return;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    SegTreeSum tree(n);
    tree.build(arr, 0, n-1, 1);
    int q, x, y;

    while(true){
        cin>>q>>x>>y;
        if(q == 0){
            /// update xth with y
            if(!tree.check(x, 0)) return 0;
            tree.update(1, 0, n-1, x, y);
        } else if (q == 1){
            if(!tree.check(x, y)) return 0;
            int sum = tree.getSum(1, 0, n-1, x, y);
            cout<<sum<<endl;
        } else {
            break;
        }
    }

    return 0;
}
