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
    ll ans = 0ll;

    if(n&1ll){
        for(ll i=3; i*i <= n; i += 2ll){
            if(n%i == 0) {
                ans += i;
                break;
            }
        }
        if(!ans) {
            /// prime
            ans += n;
        }
        k--;
    }

    /// even no. gauranteed with k moves
    ans += 2ll*k;

    cout<<ans + n<<endl;

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

