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

map<string, int> mp_mc, mp_dom;

struct Node{
    Node* prev, *nxt;
    int mc;
    Node (int val) : prev(nullptr), nxt (nullptr), mc(val){};
};

struct Proxy{
    string dom;
    int m;
    map<int, bool> up;  /// mc - true | false
    map<Node*, int> mp; /// int is id of node in the nodes vector

    Node* head; /// to be returned for the query
    Node sz; /// size of current round robin
    Node* tail;

    vector<Node*> nodes;
};

struct qNode{
    int dom;
    int mc;
    bool up;  /// to bring up the down machine if any
    int c;
};

qNode fetch(string &url){
    qNode node;

    // todo

    return node;
}

vector<vector<string>> ans(1005);

int main(){
    int n, r;



    cin>>n;
    string mc[n];
    fr(i, n) {
        cin>>mc[i];
        mp_mc[mc[i]] = i;
    }


    cin>>r;
    string ip, url;
    Proxy proxies[r];
    fr(i, r){
        cin>>proxies[i].dom>>proxies[i].m;
        mp_dom[proxies[i].dom] = i;

        fr(j, proxies[i].m){
            cin>>ip;
            Node* node = new Node( mp_mc[ip] );
            proxies[i].nodes.push_back( node );
            proxies[i].mp[node] = j;
            proxies[i].up[ mp_mc[ip] ] = true;
        }

        fr(j, proxies[i].nodes.size() - 1){
            Node* head = proxies[i].nodes[j];
            Node* tail = proxies[i].nodes[j+1];

            head->nxt = tail;
            tail->prev = head;
        }

        proxies[i].head = proxies[i].nodes[0];
        proxies[i].tail = proxies[i].nodes[proxies[i].nodes.size() - 1];
        proxies[i].sz = proxies[i].nodes.size();

    }

    int q, c;
    cin>>q;
    while(q--){

        cin>>url;

        qNode node = fetch(url);

        if(node.c == 1){
            /// find next node
            ans[ proxies[ node.dom ].head->mc ].push_back(url);

            if( proxies[ node.dom ].sz > 1 ){
                Node* head = proxies[node.dom].head;
                Node* tail = proxies[node.dom].tail;

                tail->next = head;
                head->prev = tail;
                Node* temp = head->next;
                head->next = nullptr;
                tail->prev = nullptr;

                proxies[node.dom].head = temp;
                proxies[node.dom].tail = head;
            }

        } else if (node.c == 2){
            /// disconnect

        } else {
            /// up
        }


    }

    return 0;
}
