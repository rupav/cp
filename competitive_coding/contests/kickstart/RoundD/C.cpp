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

const int N = 2e3 + 5;
vector<int> height(N), par(N), st(N);
vector<pii> euler;
vector<vector<int>> g(N);


int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

pii get(int a, int b, int c){
    int x, y;
    int g = gcd(a, b, x, y);
    x = (x * c) / g;
    y = (y * c) / g;
    pii p = {x, y};
    return p;
}

int lcm(int a, int b){
    int g = __gcd(a, b);
    return (a * b) / g;
}

int firstDepth(int x, int d, int st = 1){
    /// x is found common number, and d is lcm
    /// find first that lies on this AP >= st
    return x - ((x - st) / d) * d;
}

int countLessThanLCA(int a, int d, int lim){
    return ((lim - a) / d) + 1; /// count of AP terms within lim, greater than equal to a
}




/// Euler tour type - 3
void dfs_euler3(int v, int p, int h = 1){
    par[v] = p;
    height[v] = h;
    euler.push_back({h, v});
    for(auto u: g[v]){
        if(p == u) continue;
        dfs_euler3(u, v, h+1);
        euler.push_back({h, v});
    }
}


pii t[8 * N];

void build(int node, int tl, int tr){
    if(tr == tl) return void(t[node] = euler[tl]);
    int tm = (tl + tr)>>1;
    build(2*node, tl, tm);
    build(2*node + 1, tm+1, tr);
    t[node] = min(t[2*node], t[2*node + 1]);
}

pii get_min(int node, int tl, int tr, int l, int r){
    if(l > r) return {INT_MAX, 0};
    if(tl == l && tr == r) return t[node];
    int tm = (tl + tr)>>1;
    return min(get_min(2*node, tl, tm, l, min(r, tm)),
               get_min(2*node + 1, tm+1, tr, max(l, tm+1), r));
}




bool check(int d1, int d2, int a, int b){
    /// if they intersect
    if(abs(d1 - d2) % __gcd(a, b) == 0) return true;
    return false;
}


void solve(){
    int n, a, b, u, v;
    cin>>n>>a>>b;
    g.clear();
    euler.clear();
    rep(i, 2, n){
        cin>>v;
        g[i].push_back(v);
        g[v].push_back(i);
    }

    dfs_euler3(1, 1);
    build(1, 0, euler.size() - 1);
    int m = euler.size();
    repn(i, m - 1, 0){
        st[euler[i].second] = i;    /// first occurence of each element in euler - 1 -based indexing
    }

    int tot = 0;
    int n1, n2, n3;
    rep(u, 1, n){
        rep(v, 1, n){
            if(u == v) continue;
            /// O(n^2) approach

            /// a to u, b to v
            int start = firstDepth(height[u], a);
            n1 = countLessThanLCA(start, a, height[u]);

            start = firstDepth(height[v], b);
            n2 = countLessThanLCA(start, b, height[v]);

            tot += n1 + n2;

            if(!check(height[u], height[v], a, b)) continue;

            int lca = get_min(1, 0, m - 1, min(st[u], st[v]), max(st[v], st[u])).second;
            int z = get(a, -b, (height[u] - height[v])).first;
            z = height[u] - (z * a);  /// one of the intersecting points of u and v
            start = firstDepth(z, lcm(height[u], height[v]));
            n3 = countLessThanLCA(start, lcm(height[u], height[v]), height[lca]);

            tot -= n3;
        }
    }

    swap(a, b);

    rep(u, 1, n){
        rep(v, 1, n){
            if(u == v) continue;
            /// O(n^2) approach

            /// a to u, b to v
            int start = firstDepth(height[u], a);

            n1 = countLessThanLCA(start, a, height[u]);

            start = firstDepth(height[v], b);
            n2 = countLessThanLCA(start, b, height[v]);

            tot += n1 + n2;

            if(!check(height[u], height[v], a, b)) continue;

            int lca = get_min(1, 0, m - 1, min(st[u], st[v]), max(st[v], st[u])).second;
            int z = get(a, -b, (height[u] - height[v])).first;
            z = height[u] - (z * a);  /// one of the intersecting points of u and v
            start = firstDepth(z, lcm(height[u], height[v]));
            n3 = countLessThanLCA(start, lcm(height[u], height[v]), height[lca]);

            tot -= n3;
        }
    }



    rep(u, 1, n){
        rep(v, 1, n){
            if(u != v) continue;
            /// O(n^2) approach

            /// a to u, b to v
            int start = firstDepth(height[u], a);

            n1 = countLessThanLCA(start, a, height[u]);

            start = firstDepth(height[v], b);
            n2 = countLessThanLCA(start, b, height[v]);

            tot += n1 + n2;

            if(!check(height[u], height[v], a, b)) continue;

            int lca = get_min(1, 0, m - 1, min(st[u], st[v]), max(st[v], st[u])).second;
            int z = get(a, -b, (height[u] - height[v])).first;
            z = height[u] - (z * a);  /// one of the intersecting points of u and v
            start = firstDepth(z, lcm(height[u], height[v]));
            n3 = countLessThanLCA(start, lcm(height[u], height[v]), height[lca]);

            tot -= n3;
        }
    }


    long double exps = n * n;
    long double ans = (tot * 1.0) / exps;

    cout<<setprecision(9)<<ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll tests = 1;
    cin>>tests;
    rep(tc, 1, tests){
        cout<<"Case #"<<tc<<": ";
        solve();
        cout<<endl;
    }

    return 0;
}

