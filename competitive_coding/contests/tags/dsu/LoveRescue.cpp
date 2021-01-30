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

using pii = pair<int, int>;
vector<pii> res;

void union_set(Node* a, Node* b){
    Node* l1 = find_set(a);
    Node* l2 = find_set(b);
    if(l1 != l2){
        res.push_back({l1->val, l2->val});
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
    string s,t;
    cin>>s>>t;
    Node* nodes[26];
    for(int i=0; i<26; i++) nodes[i] = new Node(i);

    for(int i=0; i<n; i++){
        union_set(nodes[s[i]-'a'], nodes[t[i] - 'a']);
    }

    cout<<res.size()<<endl;
    for(auto it: res){
        cout<<(char)(it.first + 'a')<<" "<<(char)(it.second + 'a')<<endl;
    }

    return 0;
}
