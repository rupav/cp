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

const int N = 1e5 + 5;
ll bit[N][2];

void update(ll i, ll upd, bool f){
    if(!i) return;
    for(; i < N; i += i&(-i)) bit[i][f] += upd;
}

ll get(ll i, bool f){
    ll sum = 0ll;
    for(; i>0; i -= i&(-i)) sum += bit[i][f];
    return sum;
}

struct op{
    ll l;
    ll r;
    ll d;
};

void solve(){
    ll n, m, q, l, r, d, x, y;
    cin>>n>>m>>q;
    ll a[n];
    fr(i, n) cin>>a[i];
    fr(i, N) fr(j, 2) bit[i][j] = 0ll;
    // for(ll i=0; i<n; i++) update(i + 1ll, a[i], 1);

    vector<op> ops(m);
    fr(i, m) {
        cin>>l>>r>>d;
        ops[i] = {l, r, d};
    }

    fr(i, q){
        cin>>x>>y;
        update(x, 1ll, 0);
        update(y + 1ll, -1ll, 0);
    }

    ll fact;
    for(ll i=0; i<m; i++){
        fact = get(i+1ll, 0);
        ops[i].d *= fact;
        update(ops[i].l, ops[i].d, 1);
        update(ops[i].r + 1ll, -ops[i].d, 1);
    }

    for(ll i=0; i<n; i++){
        cout<<a[i] + get(i + 1ll, 1)<<" ";
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

