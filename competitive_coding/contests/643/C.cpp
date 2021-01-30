#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    ll A, B, C, D;
    cin>>A>>B>>C>>D;
    ll cnt = 0ll;
    ll x, y, z;
    ll x_min, d, k;

    for(ll y = B; y <= C; y++){
        z = C;
        x_min = z - y + 1ll;
        if(x_min < A){
            d = min(D - z + 1ll, A - x_min);

            cnt += (B - A + 1ll)*d;

            x_min = A;
            z = C + d;
        }
        if(x_min > B) continue;

        /// x_min is atleast A
        k = min(D - z + 1ll, B - x_min + 1ll);
        cnt += k*(B - x_min) + k - (k*(k - 1ll))/2ll;

    }

    cout<<cnt;
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

