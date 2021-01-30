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

double pi = 3.141592653589793238; //atan(1)*4;

void solve(){
    double n;
    cin>>n;
    n *= 2.0;
    double fac = sin(pi/n);
    watch(fac);
    double rad = 1.0/(2.0*fac);
    watch(rad);
    double ans = 2.0*rad;
    cout<<fixed<<setprecision(9)<<ans<<endl;
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


