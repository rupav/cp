#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* parent;
    int val;
    int s; /// size of set its in
    Node(int v, int size){
        val = v;
        s = size;
    }
};

/// DSU
Node* make_set(int val){
    Node* leader = new Node(val, 1);
    leader->parent = leader;
    return leader;
}

Node* find_set(Node* a){
    if(a->parent == a) return a;
    return a->parent = find_set(a->parent);  /// path compression algo
}

Node* union_set(Node* a, Node *b){
    Node* l1 = find_set(a);
    Node* l2 = find_set(b);
    if(l1 != l2){
        if(l1->s < l2->s){
            l1->parent = l2;
            l2->s += l1->s;
            return l2;
        } else {
            l2->parent = l1;
            l1->s += l2->s;
            return l1;
        }
    }
    return l1;
}

int main(){
    return 0;
}
