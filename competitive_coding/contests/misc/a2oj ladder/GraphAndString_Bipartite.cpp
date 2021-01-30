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

const int N = 501;
bool vis[N];
vector<int> side(N);
vector<int> deg(N);

bool checkBipartite(vector<vector<bool>> &g, int n){
    fill(side.begin(), side.end(), -1);
    int u, v;
    queue<int> q;
    bool is_bip = true;

    rep(i, 1, n){
        if(!~side[i]){
            q.push(i);
            side[i] = 0;
            while(!q.empty()){
                v = q.front();
                deg[v] = 0;
                vis[v] = 1;
                q.pop();

                rep(u, 1, n){
                    if(!g[v][u]) continue;  /// no edge
                    deg[v]++;
                    if(~side[u]){
                        is_bip &= (side[u] != side[v]);
                    } else {
                        side[u] = side[v]^1;
                        q.push(u);
                    }
                }
                if(!deg[v]) side[v] = 2;    /// isolated vertex
            }
        }
    }

    return is_bip;
}

void solve(){
    int n, m, u, v;
    cin>>n>>m;
    vector<vector<bool>> g(n + 1, vector<bool>(n + 1, true));
    fr(i, m){
        cin>>u>>v;
        g[u][v] = 0;
        g[v][u] = 0;
    }

    rep(i, 1, n) g[i][i] = 0;

    bool f = true;

    f = checkBipartite(g, n);

    string color = "";
    int cnt[2] = {0};
    if(f){
        /// color all side 0 with 'a', and side 1 with 'c'
        rep(i, 1, n){
            // watch(side[i]);
            if(!side[i]) {
                color += "a";
                cnt[0]++;
            }
            else if (side[i] == 1) {
                color += "c";
                cnt[1]++;
            }
            else color += "b";
        }
    }

    rep(i, 1, n){
        if(deg[i]){
            f &= (deg[i] == cnt[!side[i]]); /// check for complete bipartite-ness
        }
    }

    cout<<(f ? "Yes" : "No")<<endl;
    if(f) cout<<color;

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
