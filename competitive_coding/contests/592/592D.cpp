#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
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


vector<ll> cost[3];
vector<vector<int>> g;
vector<bool> vis;
vector<int> res[6];

ll dfs(int v, string &choice, int c, int i){
    vis[v] = true;
    ll sum = cost[choice[c] - '0'][v];
    res[i][v] = choice[c] - '0';
    for(auto u: g[v]){
        if(!vis[u]){
            sum += dfs(u, choice, (c+1)%3, i);
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vis.resize(n+1);
    fr(i, 3){
        cost[i].resize(n+1);
        rep(j, 1, n){
            cin>>cost[i][j];
        }
    }

    g.resize(n+1);
    /// edges
    int u, v;
    fr(i, n-1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    /// if degree is >2 for any, return -1;
    int root;
    rep(i, 1, n){
        if(g[i].size() > 2){
            cout<<-1;
            return 0;
        }
        if(g[i].size() == 1){
            /// root to start for
            root = i;
        }
    }

    fr(i, 6) res[i].resize(n+1);

    /// form the 1-line tree
    /// 6 possible choices now for painting
    string choices[] = {"012", "021", "102", "120", "201", "210"};
    int i = 0;
    ll min_cost[6];
    for(auto it: choices){
        vis.assign(n+1, false);
        ll z = dfs(root, it, 0, i);
        min_cost[i] = z;
        i++;
    }

    auto it = min_element(min_cost, min_cost+6);
    auto index = it - min_cost;
    cout<<*it<<endl;
    rep(i, 1, n){
        cout<<res[index][i]+1<<" ";
    }

    return 0;
}

