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
    ll x1, y1, z1, x2, y2, z2;
    cin>>x1>>y1>>z1>>x2>>y2>>z2;
    ll ans = 0ll;
    ll d;
    d = min(y1, x2);
    y1 -= d;
    x2 -= d;

    d = min(y1, y2);
    y1 -= d;
    y2 -= d;

    d = min(y1, z2);
    y1 -= d;
    z2 -= d;
    ans -= 2ll * d;

    /// y1 is 0
    ans += 2ll * min(z1, y2);

    cout<<ans<<endl;

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

