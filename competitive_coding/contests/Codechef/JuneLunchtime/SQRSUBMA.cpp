/// https://www.codechef.com/LTIME85A/problems/SQRSUBMA
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
    ll n, x;
    cin>>n>>x;
    ll val;
    vector<ll> pref(n + 1, 0ll);
    rep(i, 1, n){
        cin>>val;
        pref[i] = val + pref[i - 1];
    }

    /// find all size m x m submatrices, m being divisors of x <= n
    vector<ll> v;
    rep(i, 1, min(n, x)){
        if(x % i == 0) v.push_back(i);
    }

    /// max size of this v is x^(1/3) divisors. i.e. 100
    ll z;
    ll d;
    ll cnt = 0ll;
    for(auto m: v){
        /// for each m, find possible sums, and check if any 2 are equal to z = x/m;
        z = x / m;

        vector<ll> mp(z + 1ll, 0ll);
        rep(i, m, n){
            d = pref[i] - pref[i - m];
            if(d <= z)
                mp[d] += 1ll;
        }

        rep(sm, 1ll, z){
            cnt += (mp[z - sm] * mp[sm]);
        }

    }

    cout<<cnt<<endl;

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

