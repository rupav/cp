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
    int n;
    cin>>n;
    int a[n + 1];
    rep(i, 1, n) cin>>a[i];

    /// max ans can be 2
    int matches = 0;
    rep(i, 1, n){
        if(i == a[i]) matches++;
    }

    if(matches == n){
        cout<<0<<endl;
        return;
    }

    vector<int> mis;
    rep(i, 1, n){
        /// check one match in between 2 blocks of mismatch if exists
        if(i != a[i]) mis.push_back(i);
    }

    /// check if mis is cont
    bool f = (mis.back() - mis[0] + 1 == (int) mis.size());
    if(f){
        cout<<1<<endl;
    } else cout<<2<<endl;

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

