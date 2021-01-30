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

int main(){
    Node* root = new Node(3);
    root->left = new Node(10);
    root->left->right = new Node(100);
    cout<<findDistance(root, 100)<<endl;
    return 0;
}

