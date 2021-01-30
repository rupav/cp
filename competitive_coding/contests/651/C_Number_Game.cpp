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


bool solve(){
    /// for odd n, winner is that person, avoid getting to odd
    ll n;
    cin>>n;
    if(n == 1ll) return false; /// cant do
    if(n == 2ll) return true;   /// we subtract!
    if(n&1ll) return true;  /// divide by n
    ll m0 = 0ll, m1 = 0ll;    /// power of 2 and odd divisors
    while(n % 2ll == 0) {
        n/=2ll;
        m0++;
    }
    if(n == 1ll) return false;  /// we have to subtract
    if(m0 > 1ll) return true;   /// divide by the max odd divisor!
    
    /// now n is odd divisors multiple only, count such divisors
    /// check if n is prime now
    ll z = sqrt(n);
    bool f = false;
    for(ll i = 3; i <= z + 1ll; i += 2ll){
        if(n % i == 0) {
            f = true;
            break;
        }
    }

    return f;   /// atleast 2 odd divisors, otherwise we lose no matter what!
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "Ashishgup" : "FastestFinger")<<endl;
    }

    return 0;
}

