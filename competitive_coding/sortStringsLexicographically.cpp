#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
const int MAX_CHAR = 26;

struct Trie{
    int index;
    Trie* child[MAX_CHAR];

    Trie(int i = -1){
        for(int i=0; i<MAX_CHAR; i++){
            this->child[i] = NULL;
        }
        index = i;
    }
};

void trieInsert(Trie* root, string s, int index){
    Trie* node = root;

    for(auto c: s){
        int ind = c - 'a';
        if(node->child[ind] == NULL){
            node->child[ind] = new Trie();
        }

        node = node->child[ind];  /// move on.
    }

    node->index = index;  /// last element has now the index of the string in the original array!
}

void triePreorder(Trie* node, string arr[]){
    if(node == NULL)
        return;

    for(int i=0; i<MAX_CHAR; i++){
        if(node->child[i] != NULL){
            if(node->child[i]->index != -1){
                cout<<arr[node->child[i]->index]<<endl;
            }
            triePreorder(node->child[i], arr);
        }
    }
}

void printLexicographicOrder(string arr[],  int n){
    Trie *root = new Trie();
    fr(i, n){
        trieInsert(root, arr[i], i);
    }
    triePreorder(root, arr);
}

int main(){
    int i=0;
    string arr[1000];
    string s;
    while(true){
        cin>>s;
        // transform(s.begin(), s.end(), s.begin(), tolower));
        if(s[0] == '-')
            break;
        arr[i++] = s;
    }

    printLexicographicOrder(arr, i);
    vector<string> vs;
    fr(j, i){
        vs.push_back(arr[j]);
    }
    sort(vs.begin(), vs.end());
    fr(i, vs.size()){
        cout<<vs[i]<<endl;
    }
    return 0;
}

