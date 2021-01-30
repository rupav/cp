#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+1;
int t[4*N][26];
int lazy[4*N][26];
#define sz 26

void push(int node, int z){
    t[2*node][z] = lazy[node][z];
    t[2*node+1][z] = lazy[node][z];
    lazy[2*node][z] = lazy[node][z];
}

void build(string s, int node, int tl, int tr){
    if(tl == tr) return void(t[node][s[tl]] = 1);
    int tm = (tl + tr)>>1;
    build(s, 2*node, tl, tm);
    build(s, 2*node+1, tm+1, tr);
    for(int i=0; i<sz; i++){
        t[node][sz] = t[2*node][sz] + t[2*node+1][sz];
    }
}

void update(int node, int z, int tl, int tr, int l, int r, int new_val){
    if(l > r) return;
    if(tl == l && tr == r){
        t[node][z] = new_val;
        lazy[node][z] = new_val;
    } else {
        push(node, z, )
        int tm = (tl + tr)>>1;
    }
}

int main(){
    return 0;
}
