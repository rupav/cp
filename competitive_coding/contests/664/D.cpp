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
    ll n, d, m;
    cin>>n>>d>>m;
    ll a[n];
    ll szm = 0; /// <= m
    fr(i, n) {
        cin>>a[i];
        if(a[i] <= m) szm++;
    }
    sort(a, a + n, greater<ll>());
    vector<ll> prefm(szm), pref(n); /// less than equal m and so on
    ll sm = 0ll, tmp = 0ll;
    ll k = 0ll;
    fr(i, n){
        pref[i] = sm + a[i];
        sm = pref[i];
        if(a[i] <= m){
            prefm[k] = tmp + a[i];
            tmp = prefm[k];
            k++;
        }
    }

    ll mx = a[0];  // just take max
    set<pll> s;
    s.insert({0ll, 0ll});
    for(ll i = 1; i < n; i++){
        s.insert({-(i * d + 2ll), i});
    }


    /// check max for each num no. of elements
    sm = 0ll;
    for(ll num = 2; num <= n; num++){
        auto it = *s.lower_bound({-(n - num + 2ll), 0ll});
        ll z = min(it.second + 1ll, num);  /// these many elements I can take max
        if(z >= n - szm){
            /// just take all
            sm = pref[num - 1];
        } else {
            if(z >= 0){
                sm = pref[z - 1];
            }
            if(num - z - 1 >= 0){
                sm += prefm[min(szm - 1, num - z - 1)];
            }
        }
        mx = max(mx, sm);
    }
    cout<<mx;
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

