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
    ll n, l, r;
    cin>>n>>l>>r;
    l++;
    vector<ll> pref(n-1);
    ll sum = 0ll;
    map<int, ll> mp;
    fr(i, n-1){
        sum += 2ll*(n - i) - 1ll;
        pref[i] = sum;
        mp[i] = (i == 0) ? 1 : 1ll*(n - i + 1);
    }

    if(l == r){
        cout<<1;
        return;
    }

    cout<<1<<" ";

    auto lb = lower_bound(pref.begin(), pref.end(), l-1) - pref.begin();
    if(lb != 0) l -= pref[lb];

    if(l&1) cout<<mp[lb+1];
    else {
        l /= 2ll;
        cout<<2 + l - 1<<" ";
    }

    r = l;
    lb = lower_bound(pref.begin(), pref.end(), l-1) - pref.begin();
    if(lb != 0) l -= pref[lb];

    if(l&1) cout<<mp[lb+1];
    else {
        l /= 2ll;
        cout<<2 + l - 1<<" ";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }

    return 0;
}

