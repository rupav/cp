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
    ll n, k;
    cin>>n>>k;
    ll a[n];
    fr(i, n) cin>>a[i];
    ll mx = *max_element(a, a + n);
    ll mn = *min_element(a, a + n);

    if(k&1ll){
        fr(i, n) a[i] = mx - a[i];
    } else {
        fr(i, n) a[i] = a[i] - mn;
    }

    fr(i, n) cout<<a[i]<<" ";
    cout<<endl;
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

