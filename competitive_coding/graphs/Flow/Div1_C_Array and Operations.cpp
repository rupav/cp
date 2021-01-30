/// using Edmonds Karp algo on each unique prime divisor of 100 no.s with range 10e9.
/// Time complexity: O(#primes*nm^2) = O(#

#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
#define INF INT_MAX
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

const int N = 102;
vector<vector<int>> cap(N, vector<int>(N, 0)), g(N);   /// capacity[i][j] will store sum of powers of common prime divisors >1 between a[i] & a[j]
/// g is adjacency list of the graph

int countDiv(int x){
    int cnt = 0;
    int z = sqrt(x);
    rep(i, 2, z){
        while(x%i == 0) {
            x /= i;
            cnt++;
        }
    }
    if(x > 2) cnt++;    /// x itself was a prime
    return cnt;
}

int bfs(int s, int t, vector<int>& p){
    fill(p.begin(), p.end(), -1);
    p[s] = -2;
    queue<pii> q;
    q.push({s, INF});
    while(!q.empty()){
        int flow = q.front().second;
        int curr = q.front().first;
        q.pop();
        for(auto nxt: g[curr]){
            if(p[nxt] == -1 && cap[curr][nxt]){
                int new_flow = min(cap[curr][nxt], flow);
                p[nxt] = curr;
                q.push({nxt, new_flow});
                if(nxt == t) return new_flow;
            }
        }
    }
    return 0;
}


int maxFlow(int s, int t, int n){
    int new_flow, flow = 0;
    vector<int> p(n);

    while(new_flow = bfs(s, t, p)){
        int curr = t;
        while(curr != s){
            cap[curr][p[curr]] += new_flow;
            cap[p[curr]][curr] -= new_flow;
            curr = p[curr];
        }
        flow += new_flow;
    }
    return flow;
}

set<int> sp; /// holds the prime divisors of a
void findPrimes(int x){
    int z = sqrt(x);
    rep(i, 2, z){
        if(x%i == 0) sp.insert(i);
        while(x%i == 0) x /= i;
    }
    if(x >= 2) sp.insert(x);
}

int countPower(int x, int p){
    int cnt = 0;
    while(x%p == 0) {
        x /= p;
        cnt++;
    }
    return cnt;
}

void printG(int n){
    rep(i, 0, n){
        rep(j, 0, n){
            cout<<cap[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve(){
    int n, m, u, v, x;
    cin>>n>>m;
    int a[n+1];

    rep(i, 1, n){
        cin>>a[i];
        findPrimes(a[i]);
    }

    vector<pii> good_pairs;

    rep(i, 1, m){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        good_pairs.push_back({u, v});
        if(u&1) cap[u][v] = INF;
        else cap[v][u] = INF;
    }

    int s = 0, t = n + 1; /// source and sink dummy node
    rep(i, 1, n){
        if(i&1) g[s].push_back(i);
        else g[i].push_back(t);
    }


    int res = 0;
    for(auto it: sp){
        /// for each prime, find max flow in the bipartite graph, with s to A, and B to t, putting restriction on how much it can be used!
        rep(i, s, t) {
            rep(j, s, t) cap[i][j] = cap[j][i] = 0;
        }

        for(auto it: good_pairs) {
            if((it.first)&1) cap[it.first][it.second] = INF;
            else cap[it.second][it.first] = INF;
        }

        rep(i, 1, n){
            if(i&1) cap[s][i] = countPower(a[i], it);
            else cap[i][t] = countPower(a[i], it);
        }

        // printG(n + 1);

        res += maxFlow(s, t, n + 2);
    }

    cout<<res;
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

