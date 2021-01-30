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

/// CROADS
vector<ll> v;

ll solve(){
    ll n;
    cin>>n;
    auto ub = upper_bound(v.begin(), v.end(), n) - v.begin();
    int k = ub - 1;
    if(n == v[k]) return -1;

    ll ans = n/2ll - 1ll;
    /// for all odd except 1, add 1
    if(n&1ll) ans++;

    /// for even add contrib till k
    for(int i=1; i < k; i++){
        ans += v[i] + (i - 1ll)*v[i]/2ll;
    }

    /// now count contrib from even no.s between 2^k & 2^(k+1) - 1

    // watch(ans);
    ans += v[k];
    ll d = n - v[k];
    ll z, fac;


    for(int i = 1; i <= k - 1; ++i){
        fac = v[k]/v[i];
        z = d / fac;
        z += 1ll;
        z /= 2ll;
        ans += fac*z;
    }

    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll i = 1;
    while(i < 2e9 + 5){
        v.push_back(i);
        i *= 2ll;
    }

    /*
    for(auto it: v) cout<<it<<" ";
    cout<<endl;
    cout<<v.size()<<endl;
    */

    ll t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

