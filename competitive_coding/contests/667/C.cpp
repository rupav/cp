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
    ll n, x, y;
    cin>>n>>x>>y;
    ll mn[2] = {INT_MAX, INT_MAX};  // i and d of A.P
    ll z = y - x;
    ll mx = 1e18L+5;
    ll d, cnt, tmx, a;
    /// iterate over all pos diff
    rep(i, 1, n - 1){
        if(z % i == 0){
            d = z / i;
            cnt = i + 1ll;
            /// valid position, greedy
            cnt += (x - 1ll)/d;
            tmx = y + max(0ll, n - cnt) * d;
            if(tmx < mx){
                mx = tmx;
                mn[1] = d;
                mn[0] = i;
            }
        }
    }

    cnt = n;
    ll val = y;
    while(cnt > 0){
        cout<<val<<" ";
        val -= mn[1];
        cnt--;
        if(val <= 0) break;
    }
    val = y + mn[1];
    while(cnt > 0){
        cout<<val<<" ";
        val += mn[1];
        cnt--;
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

