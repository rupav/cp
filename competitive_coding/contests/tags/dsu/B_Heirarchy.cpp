#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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

bool vis[1001];

vector<Edges> Kruskal(vector<Edges> &v, int n){
    vector<Edges> result;
    vector<Node*> vertices(n+1);
    for(int i=1; i<=n; i++) vertices[i] = make_set(i);
    sort(v.begin(), v.end());
    int count = n-1;
    for(auto it: v){
        int u = it.u;
        int to = it.v;
        int w = it.weight;
        Node* x = find_set(vertices[u]);
        Node* y = find_set(vertices[to]);
        if(!vis[u] && x != y){
            result.push_back(it);
            union_set(x, y);
            count --;
        }
        vis[u] = true;
        if(count == 0) break;
    }
    return result;
}

int main(){
    int n, m, x;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>x;
    cin>>m;
    vector<Edges> v;
    while(m--){
        int x, y, w;
        cin>>x>>y>>w;
        Edges edge;
        edge.v = x;
        edge.u = y;
        edge.weight = w;
        v.push_back(edge);
    }
    vector<Edges> result = Kruskal(v, n);
    ll cost = 0ll;
    if(accumulate(vis+1, vis+n+1, 0) != n-1){
        cout<<"-1";
        return 0;
    }
    for(auto it: result){
        cost = cost + 1ll*it.weight;
    }
    cout<<cost;
    return 0;
}
