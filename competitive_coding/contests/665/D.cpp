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

void mul_self(ll &x, ll y){
    x = (x * y) % mod;
}

void add_self(ll &x, ll y){
    x += y;
    if(x >= mod) x -= mod;
}

ll n;
vector<vector<ll>>g(2e5 + 5);
vector<ll> ed;

ll dfs(ll v, ll p){
    ll tot = 1ll;
    ll cnt;
    for(auto u: g[v]){
        if(u == p) continue;
        cnt = dfs(u, v);
        add_self(tot, cnt);
        mul_self(cnt, n - cnt);
        ed.push_back(cnt);
    }
    return tot;
}

void solve(){
    ll m, u, v, k;
    cin>>n;
    fr(i, n) g[i].clear();
    ed.clear();
    fr(i, n - 1){
        cin>>u>>v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin>>m;
    vector<ll> p(m), a(n - 1, 1ll);
    fr(i, m) cin>>p[i];
    sort(p.begin(), p.end(), greater<ll>());
    if(m > n - 1ll){
        ll d = m - (n - 1ll);
        ll z = 1ll;
        fr(i, d) mul_self(z, p[i]);
        mul_self(p[d], z);
        k = 0ll;
        rep(i, d, m - 1) a[k++] = p[i];
    } else {
        fr(i, m) a[i] = p[i];
    }

    dfs(0ll, 0ll);
    sort(ed.begin(), ed.end(), greater<ll>());

    ll ans = 0ll;
    fr(i, n - 1){
        mul_self(ed[i], a[i]);
        add_self(ans, ed[i]);
    }

    cout<<ans<<endl;
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

