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

int findDistance(Node* root, int n){
    if(root == NULL)
        return -1;

    int dist = -1;
    if((root->data == n) || (dist = findDistance(root->left, n)) >=0 || (dist = findDistance(root->right, n)) >=0 )
       return dist+1;
    return dist;
}

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

int minDistance(Node* root, int m, int n){
    Node* lca = findLCA(root, m, n);
    int a = findDistance(root, m);
    int b = findDistance(root, n);
    int c = findDistance(root, lca->data);
    return a+b-2*c;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(3);
    Node* d = new Node(5);
    a->left = b;
    a->right = c;
    b->left = d;
    cout<<minDistance(a, 3, 5);
    return 0;
}

