#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> c;
typedef long long ll;

ll dfs(int v, int pc){
    // pc is parent color
    ll cnt = 0;
    for(auto u: g[v]){
        cnt += dfs(u, c[v]);
    }
    return cnt + 1ll*(pc != c[v]);
}

int main(){
    int n, p;
    cin>>n;
    g.resize(n+1);
    c.resize(n+1);
    for(int i=2; i<=n; i++){
        cin>>p;
        g[p].push_back(i);
    }

    for(int i=1; i<=n; i++){
        cin>>c[i];
    }

    cout<<dfs(1, 0);

    return 0;
}
