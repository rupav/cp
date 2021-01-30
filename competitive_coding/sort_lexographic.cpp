#include<iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX_CHAR = 26;

class Trie {
    int index;
    Trie* child[MAX_CHAR];

    Trie(){
        for(int i=0; i<MAX_CHAR; i++){
            child[i] = NULL;
        }
        index = -1;
    }
};

void insert(Trie *node, string arr[], int index){
    for(int  i=0; i<arr.size(); i++){
        int ind = arr[i] - 'a';
        if(node->child[ind] == NULL){
            node->child[ind] = new Trie();
        }
        node = node->child[ind];
    }
    node = node->index;
}

bool preorder(Trie* node, string arr[]){
    if(node == NULL){
        return false;
    }

    for(int i=0; i<MAX_CHAR; i++){
        if(node->child[i] != NULL){
            if(node->child[i]->index != -1){
                cout<<arr[node->child[i]->index];
            }
            preorder(node->child[i], arr);
        }
    }
}

void printSorted(string arr[], int n)
{
    Trie* root = new Trie();

    // insert all keys of dictionary into trie
    for (int i = 0; i < n; i++)
        insert(root, arr[i], i);

    // print keys in lexicographic order
    preorder(root, arr);
}

int main(){
    Trie* root = new Trie();

    string arr[] = { "abc", "xy", "bcd" };
    int n = sizeof(arr) / sizeof(arr[0]);
    printSorted(arr, n);
    return 0;

}
