#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


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

void solve(){
    int n;
    cin>>n;
    int a[n+2];
    rep(i, 1, n) cin>>a[i];
    vector<bool> ans(n, false);

    int p[n+1];
    rep(i, 1, n) p[a[i]] = i;

    a[0] = a[n+1] = n+1;
    int c = 0;

    Node* nodes[n+1];
    rep(i, 1, n) nodes[i] = make_set(i);

    rep(i, 1, n){
        int z = p[i];
        if((i > a[z-1]) && (i > a[z+1])){
            /// merge
            union_set(nodes[i], nodes[a[z-1]]);
            union_set(nodes[i], nodes[a[z+1]]);
            c--;
        } else {
            int min_ = min(a[z+1], a[z-1]);
            if(i > min_){
                union_set(nodes[i], nodes[min_]);
            } else {
                c++;
            }
        }
        if(c <= 1){
            ans[i-1] = true;
        }
    }

    for(auto it: ans) cout<<it;
}

void solve_without_DSU(){
    int n;
    cin>>n;
    int a[n];
    int p[n];
    fr(i, n) {
        cin>>a[i];
        p[a[i]-1] = i;
    }

    int min_p = n, max_p = -1;

    fr(pos, n){
        min_p = min(min_p, p[pos]);
        max_p = max(max_p, p[pos]);
        if(max_p - min_p + 1 == pos+1){
            cout<<1;
        } else cout<<0;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        // solve();
        solve_without_DSU();
        cout<<endl;
    }
    return 0;
}
