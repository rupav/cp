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
    /// for D<=3
    ll n, d;
    cin>>n>>d;
    ll a[n+1];
    map<ll, ll> mp;
    rep(i, 1, n) {
        cin>>a[i];
        mp[a[i]]++;
    }

    sort(a+1, a+n+1);

    ll mx = 0ll;
    for(auto it: mp) {
        mx = max(it.second, mx);
    }

    if(d == 2){
        if(n == 1){
            cout<<1;    /// has to divide
        } else {
            if(mx > 1) cout<<0;
            else cout<<1;
        }
    } else {
        /// d = 3
        if(n == 1){
            cout<<2;    /// has to divide
        } else {
            if(mx >= 3ll) cout<<0;
            else if(mx == 2){
                bool f = false;
                auto rit = mp.rbegin();
                rit++;
                while(rit != mp.rend()){
                    if(rit->second == mx) f = true;
                    rit++;
                }
                rep(i, 1, n-1) {
                    if(mp[2ll*a[i]] >= 1) {
                        f = true;
                    }
                }
                if(f) cout<<1;
                else cout<<2;
            } else {
                /// mx = 1
                bool f = false;
                rep(i, 1, n) if(mp[2ll*a[i]] >= 1) f = true;
                if(f) cout<<1;
                else cout<<2;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    rep(i, 1, t){
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<endl;
    }

    return 0;
}

