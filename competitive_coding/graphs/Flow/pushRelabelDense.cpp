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


const int N = 1e3 + 5;
const int inf = INT_MAX;
vector<int> h, ex;  /// height vector and excess flow vector
vector<vector<int>> flow, cap, g;
int n;

void push(int v, int w){
    /// push if h[v] = h[w] + 1
    int d = min(ex[v], cap[v][w] - cap[v][w]);
    flow[v][w] += d;
    flow[w][v] -= d;
    ex[v] -= d;
    ex[w] += d;
}

void relabel(int v){
    int d = inf;
    for(int w=0; w<n; w++){
        if(cap[v][w] - flow[v][w] > 0) d = min(d, h[w]);
    }
    if(d < inf) h[v] = d + 1;
}

vector<int> find_max_height(int s, int t){
    vector<int> mxh;
    for(int i=0; i<n; i++){
        if(i != s && i != t && ex[i] > 0){
            if(!mxh.empty() && h[mxh[0]] > h[i])
                mxh.clear();
            if(mxh.empty() || h[mxh[0]] == h[i])
                mxh.push_back(i);
        }
    }
    return mxh;
}

int max_flow(int s, int t){
    h.assign(n, 0);
    h[s] = n;
    flow.assign(n, vector<int>(n, 0));
    ex.assign(n, 0);
    ex[s] = inf;
    for(int i=0; i<n; i++){
        if(i != s) push(s, i);
    }

    vector<int> curr;
    while(!(curr = find_max_height(s, t)).empty()){
        for(auto i: curr){
            bool pushed = false;
            for(int j=0; j<n; j++){
                if(cap[i][j] - flow[i][j] > 0 && h[i] == h[j] + 1){
                    push(i, j);
                    pushed = true;
                }
            }
            if(!pushed){
                relabel(i);
                break;
            }
        }
    }

    int max_flow = 0;
    for(int i=0; i<n; i++){
        if(i != s) max_flow += flow[i][s];
    }
    return max_flow;
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

