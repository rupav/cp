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

vector<vector<int>> g;
vector<vector<int>> rmp;    /// reverse map

void solve(){
    int n, m, u, v;
    cin>>n>>m;
    g.resize(n + 1);
    rmp.resize(n + 1);
    vector<int> t(n+1);
    fr(i, m){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    int mx = 0;
    rep(i, 1, n){
        cin>>t[i];
        rmp[t[i]].push_back(i);
        mx = max(mx, t[i]);
    }

    vector<bool> vis(n+1, false);

    bool f = true;
    vector<int> res;
    rep(i, 1, mx){
        if((int)rmp[i].size() == 0){
            f = false;
            break;
        }
        /// for each node, check if its neighbors does not contains elements equal to its desired
        /// and check if t[neighbors] forms a segment 1 to i - 1
        for(auto u: rmp[i]){
            for(auto v: g[u]){
                vis[t[v]] = 1;
            }

            if(vis[i]){
                f = false;
                break;
            }

            rep(j, 1, i - 1){
                if(!vis[j]){
                    f = false;
                    break;
                }
            }

            if(!f) break;

            for(auto v: g[u]){
                vis[t[v]] = 0;
            }

            res.push_back(u);

        }

        if(!f) break;

    }

    if(!f){
        cout<<-1;
    } else {
        for(auto it: res) cout<<it<<" ";
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

