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

const int N = 4e5+5;

ll bit[N];
void update(int i, int n, ll upd){
    for(; i<=n; i += i&(-i)) bit[i] += upd;
}

ll get(int i){
    ll s = 0ll;
    for(; i>0; i -= i&(-i)) s += bit[i];
    return s;
}


void solve(){
    ll n, k;
    cin>>n>>k;
    ll a[n+1];

    rep(i, 1, n) cin>>a[i];
    map<ll, ll> mp;

    ll mx, mn, sm;
    rep(i, 0, 2*k) bit[i] = 0ll;
    rep(i, 1, n/2){
        mx = max(a[i], a[n-i+1]);
        mn = min(a[i], a[n-i+1]);
        sm = a[i] + a[n-i+1];

        update(mn + 1, 2*k, 1ll);
        update(mx + k + 1, 2*k, -1ll);
        mp[sm]++;
    }


    /// iterate over answer sum, x
    ll ans = n;   /// changing all
    ll cnt, bc; /// both change
    ll ops;

    rep(i, 2, 2*k){
        cnt = get(i);
        bc = (n/2ll) - cnt;
        cnt -= mp[i];
        ops = cnt + 2ll*bc;
        ans = min(ans, ops);
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

