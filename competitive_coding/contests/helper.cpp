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

/// primitive functions
ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

/// Eratosthenes sieve
void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

/// Linear Sieve
/// Totient function from 1 to n
const int MAXN = 1e5 + 5;
vector<int> prime;
bool is_composite[MAXN];
vector<int> phi;

void sieve_linear(int n){
    fill(is_composite, is_composite + n, false);
    is_composite[0] = is_composite[1] = 1;
    for(int i=2; i < n; ++i){
        if(!is_composite[i]) prime.push_back(i);
        for(int j = 0; j < prime.size() && i * prime[j] < n; ++i){
            is_composite[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;    /// since for k > j, i*prime[k] = k1*prime[j]*prime[k], i.e. our assumption would be wrong that prime[k] is the lowest prime factor of the product!
        }
    }
}

void totient_linear(int n){
    fill(is_composite, is_composite + n, false);
    phi.resize(n);
    is_composite[0] = is_composite[1] = 1;
    phi[1] = 1;
    for(int i = 2; i < n; i++){
        if(!is_composite[i]) {
            prime.push_back(i);
            phi[i] = i - 1; /// totient of a prime
        }
        for(int j = 0; j < prime.size() && i * prime[j] < n; j++){
            is_composite[i * prime[j]] = 1;
            /// case 1: prime[j] does not divide i
            phi[i * prime[j]] = phi[i]*phi[prime[j]];
            if(i % prime[j] == 0) {
                /// case 2: prime[j] divides i
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
        }
    }
}



/// strings helper functions
vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n, 0);
    int l(0), r(0);
    rep(i, 1, n-1){
        if(i <= r) z[i] = min(r-i+1, z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

/// binary exponentiation
ll binaryExponentiation(ll x, ll y){
    if(!y) return 1;
    if(y == 1) return x;
    if(y & 1ll){
        return (x*binaryExponentiation(x, y - 1ll));
    }
    ll c = binaryExponentiation(x, y/2ll);
    return c*c;
}

/// Binomial Coefficents, factorial
ll modularExponentiation(ll x, ll y, ll p = mod){
    if(y==0)
        return 1;
    if(y == 1)
        return x;
    if(y&1){
        /// y is odd, so (x*(x^(y-1)))%p
        return (x*modularExponentiation(x, y-1, p))%p;
    } else {
        /// y is even, so (x^(y/2))^2
        ll c = modularExponentiation(x, y/2, p);
        return (c*c)%p;
    }
}

const int N = 2e5 + 5;
ll fac[N];
ll inv[N];

void fill_(ll n, ll p = mod){
    fac[0] = 1ll;
    rep(i, 1, n) fac[i] = (fac[i-1]*1ll*(i))%p;
    inv[n] = modularExponentiation(fac[n], p - 2ll, p);
    repn(i, n-1, 0) inv[i] = (inv[i+1]*1ll*(i + 1ll))%p;
    return;
}

ll ncr(ll n, ll r, ll p = mod){
    return (((fac[n]*inv[n-r])%p)*inv[r])%p;
}


/// finding longest diameter in a non-rooted tree
using pii = pair<int, int>;
vector<int> p;  /// storing parents of each node
vector<vector<int>> g;  /// sparse graph
pii dfs(int v, int par, int dist = 0) {
    p[v] = par;
    pii res = {dist, v};
    for(auto u: g[v]){
        if(u != par) res = max(res, dfs(u, v, dist + 1));
    }
    return res;
}


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


/// 2D bit : Fenwick Tree
ll bit[N][2];
void update(int i, int upd, int f){
    for(; i<N; i += i&(-i)) bit[i][f] += upd;
}

ll get(int i, int f){
    ll s = 0ll;
    for(; i>0; i -= i&(-i)) s += bit[i][f];
    return s;
}


/// IMBALANCE ARRAY Preprocessing
int a[N], L[N], R[N];
typedef long long ll;

void preprocess(int n){
    stack<int> s;
    for(int i=1; i<=n; i++) L[i] = 0;
    for(int i=1; i<=n; i++) R[i] = n+1;

    for(int i=1; i<=n; i++){
        while(s.size() && a[s.top()] > a[i]) s.pop();
        if(s.size()) L[i] = s.top();  // rightmost index, s.top() s.t. a[s.top()] <= a[i]
        s.push(i);
    }

    while(s.size()) s.pop();

    for(int i=n; i>=1; i--){
        while(s.size() && a[s.top()] >= a[i]) s.pop();
        if(s.size()) R[i] = s.top();  // leftmost index, s.top() s.t. a[s.top()] < a[i]
        s.push(i);
    }
}


/// For rooted trees!
/// Euler tree - type 2 (each vertex having in and out occurences)
vector<int> tin(N), tout(N);
int T = 0;
vector<int> par(N), height(N);
vector<int> euler;

void dfsEuler2(int v, int p, int h = 0){
    tin[v] = T++;
    height[v] = h;
    par[v] = p;
    euler.push_back(v);
    for(auto u: g[v]) if(u != p) dfsEuler2(u, v, h+1);
    tout[v] = T++;
    euler.push_back(v);
}

/// Euler tree - type 3 (each vertex having #children + 1 occurences)
void dfsEuler3(int v, int p, int h = 0){
    euler.push_back(v);
    height[v] = h;
    par[v] = p;
    for(auto u: g[v]){
        if(u == p) continue;
        dfsEuler3(u, v, h+1);
        euler.push_back(v);
    }
}

bool checkBipartite(vector<vector<int>> &g, int n){
    vector<int> side(n+1, -1);
    int u, v;
    queue<int> q;
    bool is_bip = true;

    rep(i, 1, n){
        if(!~side[i]){
            q.push(i);
            side[i] = 0;
            while(!q.empty()){
                v = q.front();
                q.pop();
                for(auto u: g[v]){
                    if(~side[u]){
                        is_bip &= (side[u] != side[v]);
                    } else {
                        side[u] = side[v]^1;
                        q.push(u);
                    }
                }
            }
        }
    }

    return is_bip;
}

/// LIS:
int lis(vector<int> a, int n, bool strict){
    /// return length of longest increasing subsequence in the given array in O(nlog(n)) time
    vector<int> en;
    for(int i=0; i<n; i++){
        auto it = (strict) ? lower_bound(en.begin(), en.end(), a[i]) : upper_bound(en.begin(), en.end(), a[i]);
        if(it != en.end()) *it = a[i];
        else en.push_back(a[i]);
    }
    return en.size();
}


int main(){

    return 0;
}

