/// https://www.codechef.com/LTIME85A/problems/COWSHEDS
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
    /// solving for easier version - just simulate the whole process
    int n, q, l, r;
    cin>>n>>q;
    Node* nodes[n + 1];
    rep(i, 1, n) nodes[i] = new Node(i);
    int cnt = n;

    fr(i, q){
        cin>>l>>r;
        while(l < r){
            if(find_set(nodes[l]) != find_set(nodes[r])){
                union_set(nodes[l], nodes[r]);
                cnt--;
            } else {
                /// do nothing
            }
            l++;
            r--;
        }
        cout<<cnt<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
