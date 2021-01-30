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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcdll(a, b);
}

void solve(){
    ll n;
    cin>>n;
    ll a[n + 1];
    rep(i, 1, n) cin>>a[i];

    ll res = 0ll;
    ll g = 0ll;
    repn(i, n-1, 1){
        g = gcdll(g, a[i+1]);
        res = gcdll(res, lcm(a[i], g));
    }

    cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

