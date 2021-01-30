#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

struct Node{
    Node* p;
    vector<Node*> children;
    bool bad;
};

Node* tree[100005];

int main(){
    int n;
    cin>>n;
    int pa;
    bool isBad;
    memset(tree, NULL, sizeof(tree));
    rep(i, 1, n){
        cin>>pa>>isBad;
        if(tree[i] == NULL)
            tree[i] = new Node;

        pa = max(pa, 0);
        if(tree[pa]==NULL){
            tree[pa] = new Node;
        }

        tree[i]->p = tree[pa];
        tree[i]->bad = isBad;
        tree[i]->p->children.push_back(tree[i]);
    }

    bool atLeastOne = true;
    rep(i, 1, n){
        if(tree[i]->bad){
            bool flag = true;
            for(auto c: tree[i]->children){
                if(c->bad == false){
                    flag = false;
                    break;
                }
            }
            if(flag){
                atLeastOne = false;
                cout<<i<<" ";
                /*
                for(auto c: tree[i]->children){
                    c->p = tree[i]->p;
                    tree[i]->p->children.push_back(c);
                }
                */
            }
        }
    }

    if(atLeastOne)
        cout<<-1;

    return 0;
}

