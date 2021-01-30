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
    ll n, x, z;
    cin>>n>>x;
    vector<ll> d, pref, sm;
    ll sum = 0ll;
    ll els = 0ll;
    fr(i, n) {
        cin>>z;
        d.push_back(z);
        els += z;
        sum += (z * (z + 1ll))/2ll;
        pref.push_back(els);
        sm.push_back(sum);
    }

    x = els - x;
    ll ans = sum;

    fr(i, n) {
        d.push_back(d[i]);
        els += d[i];
        z = d[i];
        sum += (z * (z + 1ll))/2ll;
        pref.push_back(els);
        sm.push_back(sum);
    }


    /// find min sum subarray with len x
    int m = d.size();
    ll prev = 0ll;
    ll tmp;

    ll y;
    fr(i, m/2){
        /// check day '1' as 1 and last i.e. d[i]

        auto ub = upper_bound(pref.begin(), pref.end(), prev + x) - pref.begin();
        ub--;
        tmp = 0ll;
        if(ub >= 0){
            tmp += sm[ub];
            if(i > 0) tmp -= sm[i - 1];
            z = x + prev - pref[ub];
        } else z = x;

        tmp += (z * (z + 1ll))/2ll;
        ans = min(ans, tmp);

        prev += d[i];
    }

    prev = d[0];

    rep(i, 1, m/2){
        /// check day '1' as 1 and last i.e. d[i]
        tmp = d[i-1];
        auto ub = upper_bound(pref.begin(), pref.end(), prev + x - 1) - pref.begin();
        ub--;
        if(ub >= 0){
            tmp += sm[ub];
            if(i > 0) tmp -= sm[i - 1];
            z = x - 1ll + prev - pref[ub];
        } else z = x - 1ll;

        tmp += (z * (z + 1ll))/2ll;
        ans = min(ans, tmp);

        prev += d[i];
    }

    cout<<(sum/2ll) - ans;
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

