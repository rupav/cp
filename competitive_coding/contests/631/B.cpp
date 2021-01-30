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
    ll n;
    cin>>n;
    ll a[n+1];
    rep(i, 1, n) cin>>a[i];

    // map<int, int> mp1, mp2;
    ll pref[n+2] = {0}, suff[n+2] = {0};
    rep(i, 1, n) pref[i] = pref[i-1] + a[i];
    repn(i, n, 1) suff[i] = suff[i+1] + a[i];

    /*
    int mn = -1, mx = -1;
    rep(i, 1, n){
        if(mp1[a[i]]) {
            mn = mp1[a[i]];
            break;
        }
        mp1[a[i]] = i;
    }

    repn(i, n, 1){
        if(mp2[a[i]]){
            mx = i;
            break;
        }
        mp2[a[i]] = i;
    }

    if(mx != mn + 1){
        cout<<0<<endl;
        return;
    }
    */

    vector<pii> res;
    map<int, bool> mp;
    set<int> s;
    int cnt[n+1] = {0};
    rep(i, 2, n) {
        s.insert(a[i]);
        cnt[a[i]]++;
    }

    for(ll i=1; i<n; i++){
        if(mp[a[i]]) break;
        if(s.size() == (n - i) && pref[i] == (i*(i+1))/2ll && suff[i + 1] == ((n - i)*(n - i + 1))/2ll){
            res.push_back({i, n - i});
        }

        cnt[a[i+1]]--;
        if(!cnt[a[i+1]]) s.erase(a[i + 1]);
        mp[a[i]] = 1;
    }

    cout<<res.size()<<endl;
    for(auto it: res) cout<<it.first<<" "<<it.second<<endl;
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

