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
#define INF INT_MAX    /// check for this

const int N = 1e5+1;
pii t[4*N];  // min, max
int lazy[4*N] = {0};

void push(int node){
    if(!lazy[node]) return;
    t[2*node].first += lazy[node];
    t[2*node].second += lazy[node];
    lazy[2*node] += lazy[node];
    t[2*node+1].first += lazy[node];
    t[2*node+1].second += lazy[node];
    lazy[2*node+1] += lazy[node];
    lazy[node] = 0;
}

void build(int a[], int node, int tl, int tr){
    if(tl == tr) return void(t[node] = make_pair(a[tl], a[tl]));
    int tm = (tl + tr)>>1;
    build(a, 2*node, tl, tm);
    build(a, 2*node+1, tm+1, tr);
    t[node] = make_pair(min(t[2*node].first, t[2*node+1].first), max(t[2*node].second, t[2*node+1].second));
}

void update(int node, int tl, int tr, int l, int r, int add){
    if(l > r) return;
    if(tl == l && tr == r){
        t[node].first += add;
        t[node].second += add;
        lazy[node] += add;
    } else {
        push(node);
        int tm = (tl + tr)>>1;
        update(2*node, tl, tm, l, min(r, tm), add);
        update(2*node+1, tm+1, tr, max(l, tm+1), r, add);
        t[node] = make_pair(min(t[2*node].first, t[2*node+1].first), max(t[2*node].second, t[2*node+1].second));
    }
}

pii query(int node, int tl, int tr, int l, int r){
    if(l > r) return make_pair(INF, -INF);
    if(tl == l && tr == r) return t[node];
    else {
        push(node);
        int tm = (tl + tr)>>1;
        pii res[2];
        res[0] = query(2*node, tl, tm, l, min(r, tm));
        res[1] = query(2*node+1, tm+1, tr, max(l, tm+1), r);
        return make_pair(min(res[0].first, res[1].first), max(res[0].second, res[1].second));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, l, r;
    cin>>n>>m;
    int a[n];
    vector<pii> segs(m);

    for(int i=0; i<n; i++) cin>>a[i];
    build(a, 1, 0, n-1);

    map<int, vector<int>> lmp;  // all segments starting at int
    map<int, vector<int>> rmp;   // all segments ending at int

    for(int i=0; i<m; i++){
        cin>>l>>r;
        lmp[l].push_back(i);
        rmp[r].push_back(i);
        segs[i] = {l, r};
        // apply the query on seg tree
        update(1, 0, n-1, l-1, r-1, -1);
    }

    vector<int> ans(n);  // for each element, find ans, with that element assumed to be final max

    rep(i, 1, n){
        // apply all segments ending at i-1th element
        // undone all segments starting at ith element
        for(auto it: rmp[i-1]){
            update(1, 0, n-1, segs[it].first-1, segs[it].second-1, -1);
        }

        for(auto it: lmp[i]){
            update(1, 0, n-1, segs[it].first-1, segs[it].second-1, 1);
        }
        pii res = query(1, 0, n-1, 0, n-1);
        ans[i-1] = res.second - res.first;
    }

    vector<int>::iterator it = max_element(ans.begin(), ans.end());
    int ind = it - ans.begin() + 1; // now this element is assumed to be max, with 1- based indexing
    vector<int> res;

    fr(i, m){
        if(segs[i].first <= ind && segs[i].second >= ind){

        } else {
            res.push_back(i+1);
        }
    }

    cout<<*it<<endl<<res.size()<<endl;
    for(auto it: res) cout<<it<<" ";

    return 0;
}
