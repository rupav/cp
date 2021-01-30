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
    int n, x;
    cin>>n;
    vector<int> a(n + 1), b(n + 1);
    vector<int> pos(n+1, 0);
    map<int, int> mp;

    rep(i, 1, n) {
        cin>>a[i];
        pos[a[i]] = i;
    }
    int d;
    rep(i, 1, n){
        cin>>x;
        b[i] = x;
        /// only right shift poss
        if(pos[x] < i){
            d = pos[x] + n - i;
        } else d = pos[x] - i;
        mp[d]++;
    }
    mp[0] += mp[n];
    int mx = 0;
    for(auto it: mp) mx = max(mx, it.second);
    cout<<mx<<endl;
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

