#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

struct Node{
    Node* p; // parent
    int val;
    int sz;
    Node(int val){
        this->sz = 1;
        this->val = val;
        this->p = this;
    }
};

Node* findSet(Node* a){
    // returns leader of the set
    if(a->p == a) return a;
    return a->p = findSet(a->p);
}

Node* unionSet(Node* a, Node* b){
    Node* l1 = findSet(a);
    Node* l2 = findSet(b);
    if(l1 != l2){
        if(l1->sz >= l2->sz){
            l2->p = l1;
            l1->sz += l2->sz;
            return l1;
        } else {
            l1->p = l2;
            l2->sz += l1->sz;
            return l2;
        }
    }
}

map<int, Node*> mp;
int main(){
    int n;
    cin>>n;
    vector<int> z(n);
    int x;
    fr(i, n){
        cin>>x;
        z[i] = x;
        if(mp.find(x-1) != mp.end()){
            /// x-1 exists
            if(mp.find(x) != mp.end()){
                /// node for x exists somewhere
                Node* l1 = findSet(mp[x]);
                Node* l2 = findSet(mp[x-1]);
                if(l1 != l2){
                    /// then its optimal to create new x node, union in this set, and erase previous map val, replace it with new Node value
                    Node* a = new Node(x);
                    mp[x] = a;
                    unionSet(l2, a);
                } else {
                    /// ignore this element, since any no. greater than this x, will be best utilized in increasing the length of previous chain, not starting from this.
                }
            } else {
                Node* a = new Node(x);
                mp[x] = a;
                Node* l2 = findSet(mp[x-1]);
                unionSet(l2, a);
            }
        } else {
            /// x-1 doesn't exists!
            if(mp.find(x) != mp.end()){
                /// just ignore this element
                continue;
            } else {
                Node* a = new Node(x);
                mp[x] = a;
            }
        }
    }

    /// find that leader whose size is max
    int max_ = 0;
    Node* l = NULL;
    for(auto it: mp){
        Node* tl = findSet(it.second);
        if(tl->sz > max_){
            max_ = tl->sz;
            l = tl;
        }
    }

    /// max size set leader is l, now find all unique elements of it
    /// its val is the least element, and size gives us the range
    int st = l->val;
    int len = l->sz;

    vector<int> ans;
    fr(i, n){
        x = z[i];
        if(x == st){
            ans.push_back(i+1);
            len--;
            st++;
        }
        if(len == 0) break;
    }
    cout<<ans.size()<<endl;
    for(auto it: ans) cout<<it<<" ";
}
