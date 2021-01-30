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

const int nax = 5e3 + 3;
vector<vector<int>> g;
vector<vector<pii>> dp;
vector<vector<int>> cside[2];  /// each component side vertices
int comp;   /// total no. of components

bool checkBipartite(vector<vector<int>> &g, int n, int n2){
    vector<int> side(n+1, -1);
    int u, v;
    queue<int> q;
    bool is_bip = true;
    comp = 0;
    dp[0][0] = {0, 0};

    rep(i, 1, n){
        if(!~side[i]){
            pii z = {0, 0};

            q.push(i);
            side[i] = 0;
            z.first++;
            cside[0][comp].push_back(i);

            while(!q.empty()){
                v = q.front();
                q.pop();
                for(auto u: g[v]){
                    if(~side[u]){
                        is_bip &= (side[u] != side[v]);
                    } else {
                        side[u] = side[v]^1;

                        if(side[u] == 1) z.second++;
                        else z.first++;
                        cside[side[u]][comp].push_back(u);

                        q.push(u);
                    }
                }
            }

            for(int j = 0; j <= n - max(z.first, z.second); j++){
                if(~dp[comp][j].first){
                    dp[comp + 1][j + z.first] = {0, j};
                    dp[comp + 1][j + z.second] = {1, j};
                }
            }
            comp++;
        }
    }

    return is_bip && (~dp[comp][n2].first);
}

void solve(){
    int n, m, n1, n2, n3, u, v;
    cin>>n>>m;
    cin>>n1>>n2>>n3;
    g.resize(n+1);
    dp.resize(n+1, vector<pii>(n+1, make_pair(-1, -1)));
    cside[0].resize(n+1);
    cside[1].resize(n+1);

    fr(i, m){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool f = checkBipartite(g, n, n2);
    if(!f){
        cout<<"NO"<<endl;
        return;
    }

    string ans(n, '3');
    int curr = n2;
    bool side;
    while(comp){
        side = dp[comp][curr].first;
        curr = dp[comp][curr].second;
        comp--;

        for(auto el: cside[side][comp]) ans[el - 1] = '2';
        for(auto el: cside[!side][comp]) if(n1 > 0) {
            ans[el - 1] = '1';
            n1--;
        }
    }

    cout<<"YES"<<endl;
    cout<<ans;

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

