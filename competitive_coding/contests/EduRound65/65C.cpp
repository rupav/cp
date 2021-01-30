#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
vector<vector<int>> v;

struct Node{
    Node* parent;
    int val;
    int s;  /// denoting the size of set, Node is in.

    Node(int v, int size){
        val = v;
        s = size;
    }

};

/// DSU
Node* make_set(int v){
    Node *a = new Node(v, 1);
    a->parent = a;
    return a;
}

Node* find_set(Node *a){
    if(a == a->parent){
        return a;
    }

    return a->parent = find_set(a->parent);  /// path compression method
}

void union_set(Node* a, Node* b){
    Node* l1 = find_set(a);
    Node* l2 = find_set(b);
    if(l1 != l2){
        if(l1->s < l2->s){
            l1->parent = l2;
            l2->s += l1->s;
        } else {
            l2->parent = l1;
            l1->s += l2->s;
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    bool arr[n+1] = {false};
    Node* nodes[n+1];

    for(int i=1; i<=n; i++){
        nodes[i] = make_set(i);
    }

    int k;
    while(m--){
        cin>>k;
        int x;
        vector<Node*> v;
        fr(i, k){
            cin>>x;
            v.push_back(nodes[x]);
        }
        if(v.size() > 1){
            Node* a = v[v.size() - 1];
            v.pop_back();

            for(auto it: v){
                union_set(a, it);
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout<<(find_set(nodes[i]))->s<<" ";
    }

    return 0;
}
