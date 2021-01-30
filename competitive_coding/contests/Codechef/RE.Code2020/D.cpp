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
    ll n, k;
    cin>>n>>k;
    ll z = (k - 1ll)/2ll;

    if(n == 0){
        ll ans = ((k)*(k - 1))%mod;
        cout<<ans<<endl;
        return;
    }

    ll ans = ((n + z)%mod*(n + z + 1ll)%mod)%mod;
    if(k&1ll){
        ans = (ans - n + mod)%mod;
    } else {
        ans = (ans + n)%mod;
    }
    cout<<(ans + mod)%mod<<endl;
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

