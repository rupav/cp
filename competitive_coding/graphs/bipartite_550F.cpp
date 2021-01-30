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

const int N = 2e5 + 5;
vector<vector<int>> g(N);

void solve(){
    int n, m, u, v;
    cin>>n>>m;
    vector<pii> edges;
    fr(i, m){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }

    /// check for bipartite, if yes, direct edges from each side 0 to 1
    vector<int> side(n+1, -1);
    queue<int> q;
    bool is_bip = true;
    rep(i, 1, n){
        if(side[i] == -1){
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

    if(!is_bip){
        cout<<"NO";
        return;
    }

    cout<<"YES"<<endl;
    for(auto it: edges){
        cout<<side[it.first];
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

