/// find the diameter of a binary tree, given root node
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* lc;
    Node* rc;
    Node(int val): val(val), lc(nullptr), rc(nullptr){}
};

using pii = pair<int, int>;
int dia = 0;

/// returns pair<a, b> a is max distance with root as the starting, b is max dist with root as a part of it
pii find_dia(Node* root){
    if(root == NULL) return {0, 0};
    pii left = find_dia(root->lc);
    pii right = find_dia(root->rc);

    int x = max(left.first, right.first) + 1;
    int y = left.first + right.first + 1;
    dia = max({dia, x, y});
    return make_pair(x, y);
}

int main(){
    return 0;
}
