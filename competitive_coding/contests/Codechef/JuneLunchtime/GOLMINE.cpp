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
    ll n;
    cin>>n;
    /// both will mine same Gold mine on same day for optimal solution!
    double g, a, b, res[2] = {0.0, 0.0};
    double t;   /// time taken to complete
    fr(i, n){
        cin>>g>>a>>b;
        t = 1.0 / (1.0/a + 1.0/b);
        res[0] += (t / a) * g;
        res[1] += (t / b) * g;
    }
    cout<<setprecision(12)<<fixed<<res[0]<<" "<<res[1]<<endl;
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

