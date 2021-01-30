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


ll solve(){
    ll n, k;
    cin>>n>>k;
    ll a[n+1];
    rep(i, 1, n) cin>>a[i];

    bool vis[n+1] = {0};
    ll st = 1;
    ll sz = 0;
    ll lv = 1;  /// last visited
    while(!vis[st]){
        vis[st] = 1;
        lv = st;
        st = a[st];
        sz++;
    }

    st = 1;
    while(st != lv){
        st = a[st];
        k--;
        sz--;
        if(!k) return st;
    }
    k--;


    lv = a[lv];

    sz = 0;
    st = a[lv];
    while(st != lv){
        st = a[st];
        sz++;
    }
    sz++;

    // watch(sz);

    ll z = k%sz;

    st = lv;
    ll prev = st;
    rep(i, 1, z){
        st = a[st];
    }

    return st;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        cout<<solve();
    }

    return 0;
}

