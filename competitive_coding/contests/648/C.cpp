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

/// strings helper functions
vector<int> constructZFunc(vector<int>& s){
    int n = s.size();
    vector<int> z(n, 0);
    int l(0), r(0);
    rep(i, 1, n-1){
        if(i <= r) z[i] = min(r-i+1, z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    fr(i, n) cin>>a[i];
    fr(i, n) cin>>b[i];

    vector<int> c;
    fr(i, n) c.push_back(a[i]);
    c.push_back(0);
    fr(i, 2) fr(j, n) c.push_back(b[j]);

    vector<int> z = constructZFunc(c);

    int mx = 1;
    rep(i, n, z.size() - 1) mx = max(mx, min(z[i], n));

    cout<<mx<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

