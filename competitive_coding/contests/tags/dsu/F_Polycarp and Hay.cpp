#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
using pll = pair<ll, ll>;

struct Node{
    Node* p;
    ll x, y, sz;
    Node(int x, int y): x(x), y(y), p(this), sz(1ll){}
};


Node* find_set(Node* a){
    if(a->p == a) return a;
    return a->p = find_set(a->p);
}

void union_set(Node* a, Node* b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(a->sz >= b->sz){
            a->sz += b->sz;
            b->p = a;
        } else {
            b->sz += a->sz;
            a->p = b;
        }
    }
}

const int N = 1001;
const int dirs = 4;
ll n, m, k, val, x, y, x_, y_, need;
ll mat[N][N];
Node* nodes[N][N];
ll res[N][N];
map<ll, vector<pll>> mp;
bool vis[N][N];

int dirx[] = {0ll, 1ll, 0ll, -1ll};
int diry[] = {-1ll, 0ll, 1ll, 0ll};

bool check(ll x, ll y){
    if(x < 1 || x > n) return false;
    if(y < 1 || y > m) return false;
    return true;
}

ll count_ = 0ll;

void dfs(ll x, ll y){
    if(count_ == need) return;
    if(vis[x][y]) return;
    vis[x][y] = true;
    res[x][y] = val;
    count_++;
    for(int i=0; i<4; i++){
        x_ = x + dirx[i];
        y_ = y + diry[i];
        if(check(x_, y_) && nodes[x_][y_] != nullptr){
            dfs(x_, y_);
        }
    }
}

void print(){
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    cin>>n>>m>>k;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            cin>>mat[i][j];
            nodes[i][j] = nullptr;
            mp[mat[i][j]].push_back({i, j});
            vis[i][j] = false;
            res[i][j] = 0;
        }
    }

    for(auto rit = mp.rbegin(); rit != mp.rend(); rit++){
        val = rit->first;
        for(auto it: rit->second){
            x = it.first;
            y = it.second;
            nodes[x][y] = new Node(x, y);
            for(int i=0; i<dirs; i++){
                x_ = x + dirx[i];
                y_ = y + diry[i];
                if(check(x_, y_) && nodes[x_][y_] != nullptr) union_set(nodes[x_][y_], nodes[x][y]);
            }
            if(k % val == 0ll){
                need = k/val;
                if(find_set(nodes[x][y])->sz >= need){
                    // we have found the answer!
                    dfs(x, y);
                    cout<<"YES"<<endl;
                    print();
                    return 0;
                }
            } else {
                continue;
            }
        }
    }

    cout<<"NO";
    return 0;
}
