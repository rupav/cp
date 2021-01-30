#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    int sz;
    Node* p;
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

int main(){
    int n;
    cin>>n;
    Node* nodes[26];
    for(int i=0; i<26; i++) nodes[i] = new Node(i);

    map<int, bool> mp;
    string s;
    for(int i=1; i<=n; i++){
        cin>>s;
        for(auto it: s){
            union_set(nodes[s[0] - 'a'], nodes[it - 'a']);
            mp[it - 'a'] = true;
        }
    }

    set<int> res;
    for(int i=0; i<26; i++) if(mp[i]) res.insert(find_set(nodes[i])->val);

    cout<<res.size();

    return 0;
}
