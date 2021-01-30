#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

void solve(){
    ll n;
    cin>>n;
    ll b[n];
    pll a[n];
    map<ll, ll> mp;
    fr(i, n) {
        cin>>a[i].first;
        mp[a[i].first]++;
        a[i].second = i;
    }
    fr(i, n) cin>>b[i];

    sort(a, a+n, greater<pll>());

    ll x, sum(0ll);
    ll mx = 0ll;
    fr(i, n){
        if(mp[a[i].first] == 1) continue;
        sum = b[a[i].second];
        x = ~(a[i].first);

        rep(j, i+1, n-1){
            if(j == i) continue;
            if(!(x & a[j].first)) {
                x = ~(a[j].first);
                sum += b[a[j].second];
            }
        }
        mx = max(sum, mx);
    }

    cout<<mx;

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

