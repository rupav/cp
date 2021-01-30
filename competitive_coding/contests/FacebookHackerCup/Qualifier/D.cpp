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

const ll N = 2e5 + 5;
ll a[N], b[N];

vector<vector<ll>> g(N);
vector<bool> vis(N);
deque<ll> dq[2];

ll recurse(ll v){
    ll sum = a[v];
    for(auto u: g[v]){
        sum += recurse(u);
    }
    if(sum < 0){
        /// no need to transfer it further

        dq[1].push_front(v);
        return 0ll;
    } else {
        dq[0].push_back(v);
        return sum;
    }
}

void solve(){
    ll n;
    cin>>n;
    fr(i, n) cin>>a[i];
    fr(i, n) cin>>b[i];
    // g.resize(n);
    vis.assign(n, false);

    /// make chains, ending at b[i] = -1, in reverse order
    fr(i, n){
        if(vis[i]) continue;
        int j = i;
        while(b[j] != -1 && !vis[j]){
            g[b[j] - 1].push_back(j);
            vis[j] = 1;
            j = b[j] - 1;
        }
    }

    /*
    fr(i, n){
        cout<<i<<" ";
        for(auto it: g[i]) cout<<it<<" ";
        cout<<endl;
    }
    */

    vis.assign(n, false);

    fr(i, n){
        // if(vis[i]) continue;
        if(b[i] == -1){
            recurse(i);
        }
    }

    ll ans = 0ll;
    /// simulate the process as per dq

    for(auto u: dq[0]){
        ans += a[u];
        if(b[u] != -1) a[b[u] - 1] += a[u];
    }

    for(auto u: dq[1]){
        ans += a[u];
        if(b[u] != -1) a[b[u] - 1] += a[u];
    }

    cout<<ans<<endl;
    for(auto u: dq[0]){
        cout<<u + 1<<" ";
    }

    for(auto u: dq[1]){
        cout<<u + 1<<" ";
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

