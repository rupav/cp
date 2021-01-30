#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

vector<vector<int>> g;
vector<int> a;
vector<int> ans;

void dfs(int v, int p, vector<int> &en){
    auto it = lower_bound(en.begin(), en.end(), a[v]);
    ll pos = it - en.begin();
    ll temp = -1;
    if(it != en.end()) {
        temp = *it;
        *it = a[v];
    }
    else {
        en.push_back(a[v]);
    }
    ans[v] = en.size();

    for(auto u: g[v]){
        if(u == p) continue;
        dfs(u, v, en);
    }

    /// restore
    if(temp == -1){
        if(en.size())
            en.pop_back();
    } else {
        en[pos] = temp;
    }
}

void solve(){
    int n;
    cin>>n;
    g.resize(n+1);
    a.resize(n+1);
    ans.resize(n+1);
    rep(i, 1, n){
        cin>>a[i];
        /// coordinate compress to be done
    }

    int u, v;
    fr(i, n-1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> el;
    dfs(1, 1, el);

    rep(i, 1, n) cout<<ans[i]<<endl;
}

signed main(){
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

