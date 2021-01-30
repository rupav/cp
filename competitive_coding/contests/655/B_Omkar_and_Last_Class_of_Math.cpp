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
    /// a + b = n, 
    if(true || n&1ll){
        ll a = 1, b = n - 1ll;
        ll mn = n - 1ll;
        for(ll i = 2; i * i <= n; i++){
            if(n % i == 0){
                ll g = __gcd(i, n - i);
                ll l = (i * (n - i)) / g;
                if(l < mn){
                    a = i;
                    b = n - i;
                    mn = l;
                }
                ll t = i;
                i = n / t;
                g = __gcd(i, n - i);
                l = (i * (n - i)) / g;
                if(l < mn){
                    a = i;
                    b = n - i;
                    mn = l;
                }

                i = t;
            }
        }
        cout<<a<<" "<<b;
    } else {
        cout<<n/2ll<<" "<<n/2ll;
    }
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

