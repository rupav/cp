#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
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
    ll n, k;
    cin>>n>>k;
    ll a[n];
    fr(i, n) cin>>a[i];
    sort(a, a+n);
    ll pref[n] = {0};
    ll sum = 0ll;
    fr(i, n) {
        pref[i] = sum + a[i];
        sum = pref[i];
    }
    map<ll, ll> mp;

    ll cnt, cost;
    fr(i, n){
        if(mp.find(a[i]) != mp.end()){
            mp[a[i]]++;
            continue;
        }

        sum = pref[i];
        ll l(0), r(i);
        while(l <= r){
            ll m = l + (r - l)/2ll;
            cnt = 1ll*i - m + 1ll;
            cost = cnt*a[i] - (sum - (m ? pref[m-1] : 0ll));
            if(cost <= k){
                mp[a[i]] = cnt;
                r = m - 1ll;
            } else l = m + 1ll;
        }
    }

    ll max_ = -1ll;
    ll val = -1ll;
    for(auto it: mp){
        if(it.second > max_) val = it.first;
        max_ = max(max_, it.second);
    }

    cout<<max_<<" "<<val<<endl;

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

