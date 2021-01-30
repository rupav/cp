#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

struct Node{
    Node* p;
    int val;
    int sz;
    int cnt;
    Node(int val, int cnt): val(val), sz(1), p(this), cnt(cnt){}
};

Node* find_set(Node* a){
    if(a->p == a) return a;
    return a->p = find_set(a->p);
}

void union_set(Node* a, Node* b){
    Node* l1 = find_set(a);
    Node* l2 = find_set(b);
    if(l1 != l2){
        if(l1->sz >= l2->sz){
            l2->p = l1;
            l1->sz += l2->sz;
        } else {
            l1->p = l2;
            l2->sz += l1->sz;
        }
    }
}

void solve(){
    int n, m, x, y;
    cin>>n>>m;
    int w[n + 1];
    map<int, bool> mp;  /// zeros, has to be served first
    rep(i, 1, n) {
        cin>>w[i];
        if(!w[i]) mp[i] = 1;
    }
    /// make nodes on the go, if any 0
    pii cows[m + 1];
    deque<int> dq;
    bool f = true;
    Node* nodes[n + 1];
    bool vis[m + 1];
    rep(i, 1, m) {
        cin>>x>>y;
        cows[i].first = x, cows[i].second = y;
        if(mp[x] == 0 && mp[y] == 0) {
            f = false;
            break;
        }
        if(mp[x] == 0 || mp[y] == 0){
            vis[i] = 1;
            /// check if possible
            int z = (mp[x] == 0) ? y : x;
            if(nodes[z] != nullptr && nodes[z]->cnt == 0){
                f = false;
                break;
            }
            if(nodes[z] == nullptr){
                nodes[z] = new Node(z, w[z] - 1);
            } else nodes[z]->cnt--;

            /// mark them, has to be eaten first!
            dq.push_front(i);

        }
    }
    if(!f){
        cout<<"DEAD"<<endl;
        return;
    }

    /// now start connecting

    rep(i, 1, m){
        if(vis[i]) continue;
        /// both of have not 0 plates
    }

    if(!f){
        cout<<"DEAD"<<endl;
        return;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

