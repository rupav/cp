// here n = 100, so worked, I am merging two C++ sets, which is a linear time approach, so time complexity is not good for higher n.
// Instead in dfs, fill 2 sets indices, and values. Then check if both are equal, if not, return false;
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* p;
    int val;
    int sz;
    set<int> s;
    Node(int val): val(val), p(this), sz(1){
        s.insert(val);
    }
};

Node* find_set(Node* a){
    if(a->p == a) return a;
    return a->p = find_set(a->p);
}

void union_set(Node* a, Node* b){
    Node* l1 = find_set(a);
    Node* l2 = find_set(b);
    if(l1 != l2){
        set<int> s;
        merge(l1->s.begin(), l1->s.end(), l2->s.begin(), l2->s.end(), inserter(s, s.end()));
        if(l1->sz >= l2->sz){
            l1->s = s;
            l2->p = l1;
            l1->sz += l2->sz;
        } else {
            l2->s = s;
            l1->p = l2;
            l2->sz += l1->sz;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int p[n+1], fav[n+1];
    Node* nodes[n+1];
    for(int i=1; i<=n; i++){
        cin>>p[i];
        nodes[i] = new Node(p[i]);
    }
    for(int i=1; i<=n; i++){
        cin>>fav[i];
        if(i + fav[i] <= n) union_set(nodes[i], nodes[i + fav[i]]);
        if(i - fav[i] >= 1) union_set(nodes[i], nodes[i - fav[i]]);
    }

    bool f = true;
    for(int i=1; i<=n; i++){
        if(*find_set(nodes[i])->s.find(i) != i){
            f = false;
            break;
        }
    }

    if(f) cout<<"YES";
    else cout<<"NO";

    return 0;
}
