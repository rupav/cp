/// O(m^2n) approach - Edmonds Karp Algo
/// Implementation of Ford Felkurson algo, which
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

int n;
vector<vector<int>> cap, g;

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
                p[nxt] = curr;
                int new_flow = min(flow, cap[curr][nxt]);
                if(nxt == t) return new_flow;
                q.push({nxt, new_flow});
            }
        }
    }
    return 0;
}


int maxFlow(int s, int t){
    int flow = 0;
    vector<int> p(n);
    int new_flow;

    while(new_flow = bfs(s, t, p)){
        int curr = t;
        while(curr != s){
            cap[curr][p[curr]] += new_flow;  /// reverse flow
            cap[p[curr]][curr] -= new_flow;
            curr = p[curr];
        }
        flow += new_flow;
    }

    return flow;
}

void solve(){

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

