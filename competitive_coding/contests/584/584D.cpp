#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* p;
    int val;
    int sz;
    Node(int val): val(val), sz(1), p(this){}
};

Node* find_set(Node* a){
    if(a->p == a) return a;
    return a->p = find_set(a->p);
}

void union_set(Node* a, Node* b){
    Node* l1 = find_set(a);
    Node* l2 = find_set(b);
    if(l1 != l2){
        if(l1->sz >= l2->sz){
            l2->p = l1;
            l1->sz += l2->sz;
        } else {
            l1->p = l2;
            l2->sz += l1->sz;
        }
    }
}

using pii = pair<int, int>;
int main(){
    int n, k, u, v;
    cin>>n>>k;
    deque<pii> res;
    int scnt = 0;
    Node* nodes[n+1];
    for(int i=1; i<=n; i++) nodes[i] = new Node(i);
    for(int i=0; i<k; i++){
        cin>>u>>v;
        if(find_set(nodes[u]) == find_set(nodes[v])){
            scnt++;
            res.push_back({u, v});
        } else {
            union_set(nodes[u], nodes[v]);
            res.push_front({u, v});
        }
    }

    cout<<scnt<<endl;
    /*
    /// optimal order to eat
    for(auto it: res){
        cout<<it.first<<" "<<it.second<<endl;
    }
    */

    return 0;
}
