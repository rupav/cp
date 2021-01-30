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
    ll n;
    cin>>n;
    ll a[n];
    set<ll> s;
    map<ll, ll> mp;
    for(ll i=0; i<n; i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    ll val = 1;
    for(auto it: s){
        mp[it] = val++;
    }

    for(ll i=0; i<n; i++) a[i] = mp[a[i]];

    ll mx = s.size();

    vector<ll> pos[mx+1];
    for(ll i=0; i<n; i++){
        pos[a[i]].push_back(i + 1ll);
    }

    ll cnt = 1ll;
    auto prev = pos[1].begin();
    for(ll x = 1; x < mx; x++){
        /// for each x find x + 1 to leftmost right of it
        auto ub = upper_bound(pos[x + 1].begin(), pos[x+1].end(), *prev);
        if(ub == pos[x+1].end()){
            cnt++;
            prev = pos[x+1].begin();
        } else prev = ub;
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

