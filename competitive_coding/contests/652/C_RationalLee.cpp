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
    ll a[n], b[k];
    fr(i, n) cin>>a[i];
    sort(a, a + n, greater<ll>());
    fr(i, k) cin>>b[i];

    /// put largest k in all students
    /// to maximize min., try to put one with largest bag, the smallest no.
    ll res = 0ll;
    fr(i, k) res += a[i];

    reverse(a, a + n);
    int mn = 0;
    fr(i, k) b[i] -= 1ll;
    sort(b, b + k, greater<ll>());
    
    int len = 0;
    fr(i, k) {
        /// if 0, take remaining largest from here
        if(b[i] == 0){
            len = k - i;
            break;
        }
        res += a[mn];
        mn += b[i];
    }

    reverse(a, a + n);
    int i = 0;
    while(i < len) res += a[i++];

    cout<<res<<endl;

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

