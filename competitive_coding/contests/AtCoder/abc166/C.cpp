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

vector<set<ll>> g;
vector<ll> h;

void solve(){
    int n, m, u, v;
    cin>>n>>m;
    g.resize(n+1);
    h.resize(n+1);
    rep(i, 1, n) cin>>h[i];
    fr(i, m) {
        cin>>u>>v;
        g[u].insert(h[v]);
        g[v].insert(h[u]);
    }

    int cnt = 0;
    rep(i, 1, n) {
        if(!g[i].size() || h[i] > *g[i].rbegin()) cnt++;
    }
    cout<<cnt;

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

