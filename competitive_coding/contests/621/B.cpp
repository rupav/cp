#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e10+7;


ll solve(){
    ll n, x;
    cin>>n>>x;
    ll a[n];

    ll mx =  0ll;
    bool f = false;
    fr(i, n) cin>>a[i], mx = max(a[i], mx), f = (f || a[i] == x);
    if(f) return 1ll;

    if(x < mx) return 2ll;
    ll res = x/mx;
    if(x%mx != 0) res++;

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

