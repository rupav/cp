#include<bits/stdc++.h>
using namespace std;

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

vector<set<int>> g; // adjacency list

int main(){
    int n, m, u, v, s;
    cin>>n>>m;
    Node* nodes[n+1];
    for(int i=1; i<=n; i++){
        nodes[i] = new Node(i);
    }

    g.resize(n+1);

    for(int i=1; i<=m; i++){
        cin>>u>>v;
        union_set(nodes[u], nodes[v]);
        g[u].insert(v);
        g[v].insert(u);
    }

    bool f = true;
    for(int i=1; i<=n; i++){
        s = find_set(nodes[i])->sz;
        if(g[i].size() != s - 1){
            f = false;
            break;
        }
    }

    if(f) cout<<"YES";
    else cout<<"NO";

    return 0;
}

