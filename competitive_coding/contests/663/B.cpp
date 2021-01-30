#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    int n, m;
    cin>>n>>m;
    char a[n + 1][m + 1];
    rep(i, 1, n){
        rep(j, 1, m){
            cin>>a[i][j];
        }
    }
    /// just change edges!
    int cnt = 0;
    rep(i, 1, n) if(a[i][m] == 'R') cnt++;
    rep(i, 1, m) if(a[n][i] == 'D') cnt++;
    cout<<cnt<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

