#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

struct Node{
    Node* p;
    int sz;
    int val;
    Node(int val): val(val), sz(1), p(this){}
};

Node* find_set(Node* a){
    if(a->p == a) return a;
    return a->p = find_set(a->p);
}

void union_set(Node* a, Node* b){
    Node* l1 = find_set(a);
    Node* l2 = find_set(b);
    if(l1 != l2) {
        if(l1->sz >= l2->sz){
            l2->p = l1;
            l1->sz += l2->sz;
        } else {
            l1->p = l2;
            l2->sz += l1->sz;
        }
    }
}



int main(){
    int n, m, u, v;
    cin>>n>>m;
    Node* nodes[n+1];
    for(int i=1; i<=n; i++) nodes[i] = new Node(i);
    for(int i=1; i<=m; i++){
        cin>>u>>v;
        union_set(nodes[u], nodes[v]);
    }

    set<Node*> s;
    for(int i=1; i<=n; i++){
        s.insert(find_set(nodes[i]));
    }

    vector<ll> res;
    ll danger;
    for(auto it: s){
        danger = (1ll<<(it->sz - 1));
        if(danger > 1) res.push_back(danger);
    }
    ll ans = 1ll;
    for(auto it: res) ans *= it;
    cout<<ans;
}
