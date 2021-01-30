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

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
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

ll ModularExponentiation(ll x, ll y, ll max_){
    x = x%mod;
    ll res = 1;
    while(y){
        if(res >= max_) return max_;
        if(y&1){
            res = (res*x)%mod;
        }
         y = y >> 1;  /// divide by 2
         x = (x*x)%mod;
    }
    return res;
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, b; /// b is max bytes
    cin>>n>>b;
    ll k = min(n, ModularExponentiation(2, (8*b)/n, n));

    ll arr[n];
    fr(i, n) cin>>arr[i];
    sort(arr, arr+n);
    vector<ll> fv;
    ll count = 1;
    ll prev = arr[0];
    rep(i, 1, n-1){
        if(arr[i] == prev) count++;
        else {
            fv.push_back(count);
            count = 1;
        }
        prev = arr[i];
    }
    fv.push_back(count);
    fv.push_back(-1*1ll);

    if(k >= fv.size()-1){
        cout<<0;
        return 0;
    }

    ll ws = 0;  /// window sum
    ll ts = 0;
    // cout<<fv.size()<<endl;
    fr(i, fv.size()-1) ts += fv[i];
    fr(i, k){
        ws += fv[i];
    }
    ll ans = ws;
    rep(i, k, fv.size()-2){
        ws += fv[i] - fv[i-k];
        ans = max(ans, ws);
    }
    cout<<ts-ans;
    return 0;
}

