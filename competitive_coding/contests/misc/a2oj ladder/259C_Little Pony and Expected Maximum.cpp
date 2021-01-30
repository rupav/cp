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

const int N = 1e5 + 5;

double binaryExponentiation(double x, ll y){
    if(!y) return 1;
    if(y == 1) return x;
    if(y & 1ll){
        return (x*binaryExponentiation(x, y - 1ll));
    }
    double c = binaryExponentiation(x, y/2ll);
    return c*c;
}

void solve(){
    double m, n;
    cin>>m>>n;
    double ans = 0ll;
    double prev = 0.0;

    rep(i, 1, m){
        ans -= 1.0*i*prev;
        prev = binaryExponentiation(1.0*i/m, n);
        ans += 1.0*i*prev;
    }

    cout<<ans;

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

