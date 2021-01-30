#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node* head;
    Node* tail;
    Node(int val): val(val), next(nullptr), prev(nullptr), head(this), tail(this){}
};


Node* compress_tail(Node* x){
    if(x->tail == x) return x->tail;
    return x->tail = compress_tail(x->tail);
}

Node* compress_head(Node* x){
    if(x->head == x) return x->head;
    return x->head = compress_head(x->head);
}

int main(){
    int n, x, y;
    cin>>n;
    Node* nodes[n+1];
    Node* tail, *head;

    for(int i=1; i<=n; i++) nodes[i] = new Node(i);
    for(int i=1; i<n; i++){
        cin>>x>>y;
        tail = compress_tail(nodes[x]);
        head = compress_head(nodes[y]);
        tail->next = head;
        head->prev = tail;
        head->head = compress_head(tail);
        tail->tail = compress_tail(head);
    }

    head = compress_head(nodes[1]);

    while(head != nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
}
