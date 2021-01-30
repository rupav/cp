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
    int n, q;
    cin>>n>>q;
    ll a[n];
    fr(i, n) cin>>a[i];
    vector<ll> pref(n + 1, 0ll);
    rep(i, 1, n) pref[i] = pref[i - 1] + a[i - 1];

    fr(i, q){
        int l, r;
        cin>>l>>r;
        cout<<pref[r] - pref[l - 1]<<endl;
    }

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

