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
    ll n, m;
    cin>>n>>m;
    ll a[n+1], b[m+1];
    rep(i, 1, n) cin>>a[i];
    rep(i, 1, m) cin>>b[i];

    sort(a+1, a+n+1);
    sort(b+1, b+m+1);

    ll pref[n+1] = {0}, suff[m+2] = {0};

    rep(i, 1, n) pref[i] = pref[i-1] + a[i];
    repn(i, m, 1) suff[i] = suff[i+1] + b[i];

    ll ans = numeric_limits<ll>::max();
    ll x, cost;

    rep(i, 1, n){
        cost = 0ll;
        x = a[i];
        cost += (x*1ll*i - pref[i]);
        auto lb = lower_bound(b+1, b+m+1, x) - (b);
        cost += (suff[lb] - 1ll*(m + 1ll - lb)*x);
        if(cost > ans) break;
        ans = min(ans, cost);
    }

    repn(i, m, 1){
        cost = 0ll;
        x = b[i];
        cost += (suff[i] - 1ll*(m + 1ll - i)*x);
        auto ub = upper_bound(a+1, a+n+1, x) - (a);
        ub--;
        cost += (x*1ll*ub - pref[ub]);
        if(cost > ans) break;
        ans = min(cost, ans);
    }

    cout<<ans;

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

