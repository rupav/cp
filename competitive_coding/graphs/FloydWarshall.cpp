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

vector<vector<int>> d;  /// shortest distance matrix
vector<vector<int>> g;

const int inf = numeric_limits<int>::max();

void floydWarshall(int n){
    rep(k, 1, n){
        rep(i, 1, n){
            rep(j, 1, n){
                if(d[i][k] < inf && d[k][j] < inf)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void solve(){
    int n, m, u, v, w;
    cin>>n>>m;
    d.resize(n+1, vector<int>(n+1, inf));

    fr(i, m){
        cin>>u>>v>>w;
        d[u][v] = w;
    }

    floydWarshall(n);

    rep(i, 1, n){
        rep(j, 1, n){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
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

