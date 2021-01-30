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

vector<vector<int>> g;
vector<ll> sum;
vector<bool> vis;
vector<int> tin, low, val;
int timer;

void is_bridge(int a, int b){
    cout<<a+1<<" "<<b+1<<endl;
    return;
}

ll dfs(int v, int parent = -1){
    vis[v] = true;
    tin[v] = low[v] = timer++;

    for(auto to: g[v]){
        if(to == parent) continue; /// since is an undirected graph
        if(vis[to]){
            low[v] = min(low[v], tin[to]);
        } else {
            ll temp = dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(tin[v] < low[to]){
                /// we have found a bridge!
                is_bridge(v, to);
                sum[to] = temp;
            }
        }
    }
}

void find_bridges(int n, int source = 0){
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    timer = 0;

    dfs(source);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    val.resize(n);
    fr(i, n) cin>>val[i];
    g.resize(n);
    sum.assign(n, 0);
    int x, y;
    fr(i, m){
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int source;
    cin>>source;
    source--;
    find_bridges(n, source);

    return 0;
}
