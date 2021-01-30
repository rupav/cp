#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

struct Node{
    int data;
    Node *left, *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* findLCA(Node* root, int m, int n){
    /// assuming both m & n exists in the binary tree.
    if(root == NULL)
        return root;

    if(root->data == m || root->data == n)
        return root;

    Node* left = findLCA(root->left, m, n);
    Node* right = findLCA(root->right, m, n);

    if(left != NULL && right != NULL)
        return root;

    return (left == NULL) ? right : left;
}

int main(){
    return 0;
}
