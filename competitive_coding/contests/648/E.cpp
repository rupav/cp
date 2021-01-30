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
    ll n;
    cin>>n;
    ll a[n];
    ll mx = 0ll;
    fr(i, n) cin>>a[i];

    if(n <= 2){
        fr(i, n) mx |= a[i];
    }

    fr(i, n){
        rep(j, i + 1, n-1){
            rep(k, j + 1, n-1){
                mx = max(mx, a[i] | a[j] | a[k]);
            }
        }
    }

    cout<<mx<<endl;
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

