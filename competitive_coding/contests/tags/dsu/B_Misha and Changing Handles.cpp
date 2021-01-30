#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* p;
    string val;
    Node(string s): val(s), p(this){}
};

Node* find_set(Node* a){
    if(a->p == a) return a;
    return a->p = find_set(a->p);
}

Node* union_set(Node* a, Node* b){
    a = find_set(a);
    b = find_set(b);
    a->p = b;
}

map<string, Node*> mp;
vector<string> old;
int main(){
    int q;
    cin>>q;
    string s, t;
    for(int i=1; i<=q; i++){
        cin>>s>>t;
        if(mp[s]){
            Node* y = new Node(t);
            union_set(mp[s], y);
            mp[t] = find_set(mp[s]);
        } else {
            Node* x = new Node(s);
            Node* y = new Node(t);
            union_set(x, y);
            mp[s] = mp[t] = y;
            old.push_back(s);
        }
    }

    cout<<old.size()<<endl;
    for(auto it: old){
        cout<<it<<" "<<find_set(mp[it])->val<<endl;
    }

    return 0;
}
