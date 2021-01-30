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


ll getMin(ll a, ll b, ll x, ll y, ll n){
    ll d = a - x;
    a -= min(n, d);
    n -= min(n, d);
    d = b - y;
    b -= min(n, d);
    n -= min(n, d);
    return a * b;
}

void solve(){
    ll a, b, x, y, n;
    cin>>a>>b>>x>>y>>n;
    cout<<min(getMin(a, b, x, y, n), getMin(b, a, y, x, n))<<endl;
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

