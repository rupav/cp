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


bool solve(){
    int n, x, u, v;
    cin>>n>>x;
    vector<vector<int>> g(n + 1);
    rep(i, 1, n - 1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    watch(g[x].size());
    if(g[x].size() == 1){
        return true;
    }

    int m = g[x].size();
    int z = n - m - 1;

    return (z&1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "Ayush" : "Ashish")<<endl;
    }

    return 0;
}

