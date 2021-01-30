#include<bits/stdc++.h>
using namespace std;

struct Edges{
    int u, v, weight;
    bool operator< (Edges const& other){
        return weight < other.weight;
    }
};

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

vector<Edges> Kruskal(vector<Edges> &v, int n){
    vector<Edges> result(n-1);
    vector<Node*> vertices(n);
    for(int i=0; i<n; i++) vertices[i] = make_set(i);
    sort(v.begin(), v.end());
    int count = n-1;
    for(auto it: v){
        int u = it.u;
        int to = it.v;
        int w = it.weight;
        Node* x = find_set(vertices[u]);
        Node* y = find_set(vertices[to]);
        if(x != y){
            result.push_back(it);
            union_set(x, y);
            count --;
        }
        if(count == 0) break;
    }
    return result;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<Edges> v(m);
    while(m--){
        int x, y, w;
        cin>>x>>y>>w;
        Edges edge;
        edge.u = x;
        edge.v = y;
        edge.weight = w;
        v.push_back(edge);
    }
    vector<Edges> result = Kruskal(v, n);
    for(auto it: result){
        cout<<it.u<<" "<<it.v<<endl;
    }
    return 0;
}
