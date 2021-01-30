#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)

typedef struct Node{
    int val;
    Node* next;

    Node(int i = 0){
        /// constructor
        this->val = i;
        this->next = NULL;
    }
} Node_t;

int main(){

    Node_t *root = new Node_t(-1);
    Node_t* temp = root;

    while(true){
        int x;
        cin>>x;
        if(x == -1) break;
        Node_t *newNode = new Node_t(x);
        temp->next = newNode;
        temp = newNode;
    }

    /// remove first node.
    temp = root->next;
    delete(root);
    root = temp;

    while(temp!=NULL){
        temp = temp->next;
    }

    Node *fast = root->next;
    Node *slow = root;

    /// checking if LL is palindrome


    return 0;
}
