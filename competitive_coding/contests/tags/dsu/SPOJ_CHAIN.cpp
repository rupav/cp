#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

/// DSU
struct Node{
    Node* p;
    int val;
    int sz;
    Node(int val): val(val), sz(1), p(this) {}
};


Node* find_set(Node* a) {
    if(a->p == a) return a;
    return a->p = find_set(a->p);
}

Node* union_set(Node* a, Node* b){
    Node* l1 = find_set(a);
    Node* l2 = find_set(b);
    if(l1 == l2) return l1;
    if(l1->sz >= l2->sz){
        l2->p = l1;
        l1->sz += l2->sz;
        return l1;
    } else {
        l1->p = l2;
        l2->sz += l1->sz;
        return l2;
    }
}

void solve(){
    int n, m, x, y, c;
    cin>>n>>m;
    vector<Node*> nodes(n + 1);
    rep(i, 1, n) nodes[i] = new Node(i);

    int cnt = 0;
    fr(i, m){
        cin>>c>>x>>y;
        c--;
        if(c){
            /// check if equal!

        } else {

        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

