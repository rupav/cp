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
    ll n, m, k;
    cin>>n>>m>>k;
    bool a[n], b[m];
    fr(i, n) cin>>a[i];
    fr(i, m) cin>>b[i];
    ll res = 0ll;

    vector<ll> fac;
    for(ll i=1; i*i <= k; i++){
        if(k%i == 0) fac.push_back(i);
    }

    ll k1, k2, temp;
    ll cnt1, cnt2;
    int sum = 0;
    for(auto f: fac){
        /// count of continuous subsegments with 1s only of length k1 or k2
        k1 = f;
        k2 = k/f;
        fr(z, 2){

            sum = 0;
            cnt1 = 0ll;
            fr(i, min(k1, n)) sum += a[i];
            if(sum == k1) cnt1 += 1ll;
            rep(i, k1, n-1) {
                sum -= a[i - k1];
                sum += a[i];
                if(sum == k1) cnt1 += 1ll;
            }

            sum = 0;
            cnt2 = 0ll;
            fr(i, min(k2, m)) sum += b[i];
            if(sum == k2) cnt2 += 1ll;
            rep(i, k2, m-1) {
                sum -= b[i - k2];
                sum += b[i];
                if(sum == k2) cnt2 += 1ll;
            }

            res += cnt1*cnt2;

            if(k1 == k2) break;
            /// swap
            k1 = k2;
            k2 = k/k2;
        }
    }

    cout<<res;

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

