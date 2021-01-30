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

Node* reverseLL(Node* root){
    if(root->next == NULL) return root;
    Node* temp = root->next;
    Node* head = reverseLL(root->next);
    temp->next = root;
    root->next = NULL;
    return head;
}

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

    Node *fast = root->next;
    Node *slow = root;

    /// checking if LL is palindrome
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    /// now slow is middle element!
    Node* reverse_root = reverseLL(slow);
    Node* head[2] = {root, reverse_root};

    /// now compare the 2 lists.
    while(head[0] != NULL && head[1] != NULL){
        if(head[0]->val != head[1]->val){
            cout<<"Not a palindrome!!!"<<endl;
            return 0;
        }
        head[0] = head[0]->next;
        head[1] = head[1]->next;
    }

    cout<<"Palindrome!"<<endl;

    return 0;
}
