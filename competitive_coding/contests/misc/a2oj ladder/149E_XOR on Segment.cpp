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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

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

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

const int sz = 20;
const int N = 1e5 + 5;
int t[4* N][sz], lazy[4 * N][sz];
bool a[N][sz];

void push(int v, int tl, int tr, int tm, int tn){
    int &flips = lazy[v][tn];
    t[2*v][tn] = (flips&1) ? (tm - tl + 1 - t[2*v][tn]) : t[2*v][tn];
    t[2*v + 1][tn] = (flips&1) ? (tr - tm - t[2*v + 1][tn]) : t[2*v + 1][tn];
    lazy[2*v][tn] += flips;
    lazy[2*v + 1][tn] += flips;
    flips = 0;
}

void build(int v, int tl, int tr, int tn){
    if(tl == tr) return void(t[v][tn] = a[tl][tn]);
    int tm = (tl + tr) / 2;
    build(2*v, tl, tm, tn);
    build(2*v + 1, tm+1, tr, tn);
    t[v][tn] = t[2*v][tn] + t[2*v + 1][tn];
}

void update(int v, int tl, int tr, int l, int r, int tn){
    if(l > r) return;
    if(tl == l && tr == r){
        t[v][tn] = (r - l + 1 - t[v][tn]);
        lazy[v][tn] += 1;
    } else {
        int tm = (tl + tr) / 2;
        push(v, tl, tr, tm, tn);
        update(2*v, tl, tm, l, min(r, tm), tn);
        update(2*v + 1, tm+1, tr, max(l, tm + 1), r, tn);
        t[v][tn] = t[2*v][tn] + t[2*v + 1][tn];
    }
}

int query(int v, int tl, int tr, int l, int r, int tn){
    if(l > r) return 0;
    if(tl == l && tr == r) return t[v][tn];
    int tm = (tl + tr) / 2;
    push(v, tl, tr, tm, tn);
    return query(2*v, tl, tm, l, min(r, tm), tn) + query(2*v + 1, tm + 1, tr, max(l, tm + 1), r, tn);
}

void solve(){
    int n, l, r, c, q, x;
    cin>>n;
    int arr[n];
    fr(i, n) {
        cin>>arr[i];
        x = arr[i];
        fr(j, sz){
            a[i][j] = (bool)((1<<j)&x);
        }
    }

    fr(i, 4*N) fr(j, sz) lazy[i][j] = 0;

    fr(j, sz) build(1, 0, n-1, j);

    cin>>q;

    while(q--){
        cin>>c;
        if(c == 1){
            /// sum
            cin>>l>>r;
            l--, r--;
            ll fac = 1ll;
            ll res = 0ll;
            ll temp;
            fr(j, sz){
                temp = 1ll*query(1, 0, n-1, l, r, j);
                res += fac*temp;
                fac *= 2ll;
            }
            cout<<res<<endl;
        } else {
            /// execute xor on a range
            cin>>l>>r>>x;
            l--, r--;
            fr(j, sz){
                if((1<<j)&x){
                    /// flip
                    update(1, 0, n-1, l, r, j);
                }
            }
        }
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

