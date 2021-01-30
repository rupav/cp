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
    ll x, y, a, b;
    cin>>x>>y>>a>>b;

    if(!x && !y){
        cout<<0<<endl;
        return;
    }

    if(x > y){
        ll t = y;
        y = x;
        x = t;
    }

    /// y > x
    ll cost = 0ll;
    ll res = 0ll;
    if(!x){
        res = a;  /// x to 1
        x++;
    }

    res += b;   /// to reach 0

    res += (y - x)*a;
    /// find min to reach 1

    cost = min((x - 1ll)*2ll*a, (x - 1ll)*b);

    cout<<cost + res<<endl;
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

