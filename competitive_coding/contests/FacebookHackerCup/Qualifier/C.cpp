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

#define p first
#define h second

void solve(){
    ll n;
    cin>>n;
    vector<pll> v(n);
    fr(i, n) cin>>v[i].p>>v[i].h;
    sort(v.begin(), v.end());

    map<ll, ll> mp; /// stores the answer for each point being the last point as the longest interval of timber
    ll ans = 0ll;
    ll len;
    fr(i, n){
        len = mp[v[i].p] + v[i].h;
        mp[v[i].p + v[i].h] = max(len, mp[v[i].p + v[i].h]);    /// update
        ans = max(mp[v[i].p + v[i].h], ans);

        len = mp[v[i].p - v[i].h] + v[i].h;
        mp[v[i].p] = max(mp[v[i].p], len);   /// tree put to the left
        ans = max(ans, len);

    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("timber_input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll t = 1;
    cin>>t;
    rep(i, 1, t){
        cout<<"Case #"<<i<<": "<<endl;
        solve();
    }

    return 0;
}


/*

1
5
3 2
2 8
-4 5
8 5
1 4

*/
