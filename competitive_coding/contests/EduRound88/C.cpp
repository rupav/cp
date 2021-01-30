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




void solve(){
    long double h, c, t, s;
    cin>>h>>c>>t;
    s = h + c;

    int ans = 2;
    long double mn = s/2.0;
    mn = abs(mn - t);

    int n = (h - t)/(2.0 * t - s);

    long double val = (1.0 * n * s + h) / (2.0 * n + 1.0);
    if(abs(val - t) < mn){
        mn = abs(val - t);

        ans = 2ll * n + 1ll;
    }

    n++;
    val = (1.0 * n * s + h ) / (2.0 * n + 1.0);
    if(abs(val - t) < mn){
        mn = abs(val - t);
        ans = 2ll * n + 1ll;
    }

    if(abs(h - t) <= mn){
        ans = 1;
    }

    if(ans < 0) cout<<2<<endl;
    else cout<<ans<<endl;

}

signed main(){
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

