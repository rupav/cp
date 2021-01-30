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


void solve(){
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    bool f = (n * a == m * b);

    vector<vector<bool>> mat(n, vector<bool>(m, 0));

    fr(i, a * n){
        mat[i / a][i % m] = 1;
    }

    if(f){
        cout<<"YES"<<endl;
        fr(i, n){
            fr(j, m) cout<<mat[i][j];
            cout<<endl;
        }
    } else cout<<"NO"<<endl;

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

