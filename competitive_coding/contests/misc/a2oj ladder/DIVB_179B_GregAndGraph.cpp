#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

vector<int> o;  /// order of phases - k
vector<vector<int>> d;  /// shortest distance at each phase
vector<int> el; /// added elements so far
vector<int> ans;

const int inf = numeric_limits<int>::max();


void floydWarshall(int n){
    rep(k, 1, n){
        el.push_back(o[k]);
        rep(i, 1, n){
            rep(j, 1, n){
                d[i][j] = min(d[i][j], d[i][o[k]] + d[o[k]][j]);
            }
        }
        int cost = 0;
        for(auto it: el){
            for(auto jit: el){
                if(it == jit) continue;
                cost += d[it][jit];
            }
        }
        ans.push_back(cost);
    }
}

void solve(){
    int n, w, x;
    cin>>n;
    d.resize(n+1);
    rep(i, 0, n) {
        d[i].resize(n+1, inf);
    }

    rep(i, 1, n){
        rep(j, 1, n){
            cin>>w;
            d[i][j] = w;
        }
    }

    o.resize(n+1); /// order of addition of elements
    rep(i, 1, n) cin>>o[i];
    reverse(o.begin() + 1, o.end());
    o[0] = 0;


    floydWarshall(n);

    /// now d[k] will store distance between each pair of nodes with vertices {1, 2, ..., k} only

    reverse(ans.begin(), ans.end());
    for(auto it: ans) cout<<it<<" ";

}

signed main(){
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

