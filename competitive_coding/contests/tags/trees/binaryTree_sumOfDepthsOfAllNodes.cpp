#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val), left(nullptr), right(nullptr){}
};

int dfs(Node* root, int depth){
    if(root == NULL) return 0;
    return depth + dfs(root->left, depth + 1) + dfs(root->right, depth + 1);
}

void solve(){
    /// given a binary tree root node, find the sum of depths of all nodes, with root node depth = 0
    int n;
    cin>>n;
    Node* nodes[2*n + 1];
    nodes[0] = new Node(1);
    rep(i, 1, n - 1) nodes[i] = new Node(i+1);
    rep(i, n, 2*n) nodes[i] = nullptr;

    rep(i, 1, n-1){
        nodes[i-1]->left = nodes[2*i - 1];
        nodes[i-1]->right = nodes[2*i];
    }

    Node* root = nodes[0];

    cout<<dfs(root, 0)<<endl;
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

