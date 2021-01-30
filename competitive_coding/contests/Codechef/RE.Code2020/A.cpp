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


/// https://www.codechef.com/RC122020/problems/RECNDROT
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    map<ll, ll> st, lt; /// first pos of each & last pos of each
    vector<ll> v;   /// sorted elements store
    set<ll> s;
    fr(i, n) {
        cin>>a[i];
        if(st.find(a[i]) == st.end()) st[a[i]] = i;
        lt[a[i]] = i;
        s.insert(a[i]);
    }
    for(auto it: s) v.push_back(it);

    // for(auto it: v) cout<<it<<" ";
    // cout<<endl;

    ll m = v.size();
    ll ans = 1ll;

    ll x;
    fr(i, m - 1){
        if(st[v[i]] > lt[v[i+1]]) ans++;
    }

    cout<<ans<<endl;

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

