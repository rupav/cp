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
    ll n, m;
    cin>>n>>m;
    /// find fibo of n & m
    ll fib[max(n, m) + 1];
    fib[0] = fib[1] = 1ll;
    rep(i, 2, max(n, m)){
        fib[i] = (fib[i- 1] + fib[i - 2])%mod;
    }

    ll ans = 0ll;
    ans = ((fib[n] + fib[m] - 1)*2ll)%mod;
    cout<<(ans + mod)%mod;
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

