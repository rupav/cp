#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

vector<vector<int>> g;
vector<pii> h;
vector<bool> vis;
vector<int> ht;

/// DSU
struct Node{
    Node* p;
    int val;
    int sz;
    Node(int val): val(val), sz(1), p(this) {}
};

Node* find_set(Node* a) {
    if(a->p == a) return a;
    return a->p = find_set(a->p);
}

Node* union_set(Node* a, Node* b){
    Node* l1 = find_set(a);
    Node* l2 = find_set(b);
    if(l1 == l2) return l1;
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


void dfs(int v, int p, vector<Node*>& comp){
    vis[v] = 1;
    for(auto u: g[v]){
        if(u == p) continue;
        if(vis[u]) continue;
        if(ht[v] > ht[u]){
            union_set(comp[v], comp[u]);
            dfs(u, v, comp);
        }
    }
}



void solve(){
    int n, q, u, v;
    cin>>n>>q;

    g.clear();
    h.clear();
    vis.clear();
    ht.clear();
    g.resize(n + 1);
    h.resize(n + 1);
    vis.resize(n+1, false);
    ht.resize(n+1);

    map<pii, bool> mp;

    fr(i, n - 1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u, v}] = 1;
        mp[{v, u}] = 1;
    }

    rep(i, 1, n){
        cin>>h[i].first;
        h[i].second = i;
        ht[i] = h[i].first;
    }
    h[0] = {0, 0};

    sort(h.begin(), h.end(), greater<pii>());

    vector<Node*> comp(n+1);

    rep(i, 1, n) comp[i] = new Node(i);

    for(auto it: h){
        if(it.second && !vis[it.second]){
            dfs(it.second, it.second, comp);
        }
    }

    string res;
    fr(i, q){
        cin>>u>>v;
        if(find_set(comp[u]) == find_set(comp[v])) {
            res += '1';
            continue;
        }

        cout<<find_set(comp[u])->val<<endl;
        cout<<find_set(comp[v])->val<<endl;

        bool f = false;
        map<Node*, bool> cm;
        for(auto x: g[u]){
            if(ht[x] > ht[u]) cm[find_set(comp[x])] = 1;
            /*
            if(ht[x] > ht[u] && find_set(comp[x]) == find_set(comp[v])) {
                f = true;
                break;
            }
            */
        }
        cm[find_set(comp[u])] = 1;

        for(auto x: g[v]){
            if(ht[x] > ht[v]){
                if(cm[find_set(comp[x])]) f = true;
            }
            /*
            if(ht[x] > ht[v] && find_set(comp[x]) == find_set(comp[u])) {
                f = true;
                break;
            }
            */
        }
        if(cm[find_set(comp[v])]) f = true;

        if(f) res += '1';
        else res += '0';
    }

    cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*

1
15 100
1 2
2 7
7 8
7 9
1 3
3 4
3 5
5 10
5 6
5 11
5 12
11 13
12 14
14 15
1 2 3 4 15 6 8 10 9 7 11 14 13 5 12

*/

