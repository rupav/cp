#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int val): val(val), next(nullptr), prev(nullptr){}
};

const int N = 1e6+5;
Node* nodes[N];

int main(){
    int n, x, y;
    cin>>n;
    for(int i=0; i<=N; i++) nodes[i] = new Node(i);
    for(int i=0; i<n; i++){
        cin>>x>>y;
        nodes[x]->next = nodes[y];
        nodes[y]->prev = nodes[x];
    }

    Node* h1 = nodes[0]->next;
    Node* tail = nodes[0]->prev;
    while(tail->prev != nullptr){
        tail = tail->prev;
    }
    Node* h2 = tail;

    while(h2 != nodes[0] && h1 != nullptr){
        cout<<h2->val<<" "<<h1->val<<" ";
        h2 = h2->next;
        h1 = h1->next;
    }

    while(h2 != nodes[0]) {
        cout<<h2->val<<" ";
        h2 = h2->next;
    }

    while(h1 != nullptr){
        cout<<h1->val<<" ";
        h1 = h1->next;
    }

    return 0;
}
