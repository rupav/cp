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
    Node* p;
    int x;
    int y;
    int sz;
    Node(int r, int c): x(r), y(c), sz(1), p(this){}
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

ll calc(pii a, pii b){
    return (1ll*a.first - 1ll*b.first)*(1ll*a.first - 1ll*b.first) + (1ll*a.second - 1ll*b.second)*(1ll*a.second - 1ll*b.second);
}

map<pii, vector<pii>> g;
vector<pii> comp[2];
bool vis[51][51];

bool mat[52][52];  // 1 by land and 0 by water

void dfs(pii a, bool f, int n){
    if(vis[a.first][a.second]) return;
    vis[a.first][a.second] = true;
    comp[f].push_back(a);
    for(auto it: g[a]){
        dfs(it, f, n);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int r1, c1, r2, c2;
    cin>>r1>>c1>>r2>>c2;
    string s;
    Node* nodes[n+1][n+1];
    for(int i=1; i<=n; i++){
        cin>>s;
        for(int j=1; j<=n; j++){
            nodes[i][j] = new Node(i, j);
            mat[i][j] = 1 - (int)(s[j-1] - '0');
            if(mat[i][j]){
                // land
                if(i>1 && mat[i-1][j]){
                    union_set(nodes[i-1][j], nodes[i][j]);
                    g[{i, j}].push_back({i-1, j});
                }
                if(j>1 && mat[i][j-1]){
                    union_set(nodes[i][j], nodes[i][j-1]);
                    g[{i, j}].push_back({i, j-1});
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i < n && mat[i+1][j]) g[{i, j}].push_back({i+1, j});
            if(j < n && mat[i][j+1]) g[{i, j}].push_back({i, j+1});
        }
    }

    ll ans = mod;

    // find only those cells having r1, c1 and r2, c2
    Node* src = find_set(nodes[r1][c1]);
    Node* dest = find_set(nodes[r2][c2]);
    if(src == dest){
        cout<<"0";
        return 0;
    }

    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            Node* l = find_set(nodes[i][j]);
            if(l == src) comp[0].push_back({i, j});
            if(l == dest) comp[1].push_back({i, j});
        }
    }
    */

    dfs({r1, c1}, 0, n);
    dfs({r2, c2}, 1, n);

    ll temp;
    for(auto it: comp[0]){
        for(auto jit: comp[1]){
            temp = calc(it, jit);
            ans = min(temp, ans);
        }
    }
    cout<<ans;

    return 0;
}
