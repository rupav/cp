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
        if(true || l1->sz >= l2->sz){
            l2->p = l1;
            l1->sz += l2->sz;
        } else {
            l1->p = l2;
            l2->sz += l1->sz;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[n+1];
    Node* nodes[n+1];
    for(int i=1; i<=n; i++) nodes[i] = new Node(i);

    for(int i=1; i<=n; i++){
        cin>>a[i];
        union_set(nodes[a[i]], nodes[i]);
    }

    set<int> s;
    for(int i=1; i<=n; i++){
        s.insert(find_set(nodes[i])->val);
    }


    int cnt = 0;
    int l = -1;
    for(auto it: s){
        if(a[it] == it){
            l = it;  // make this leader, since it already has a unit length loop!
            break;
        }
    }
    if(l == -1){
        l = *s.begin();  // make any other cycle's vertex as the leader
        a[l] = l;
        cnt++;
    }

    for(auto it: s){
        if(it != l){
            a[it] = l;
            cnt++;
        }
    }

    cout<<cnt<<endl;
    for(int i=1; i<=n; i++) cout<<a[i]<<" ";

}
