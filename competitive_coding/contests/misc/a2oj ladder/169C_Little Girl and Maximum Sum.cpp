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

const int N = 2e5 + 5;
ll bit[N] = {0};

void update(ll i, ll upd){
    for(; i < N; i += i&(-i)) bit[i] += upd;
}

ll get(ll i){
    ll sum = 0;
    for(; i > 0; i -= i&(-i)) sum += bit[i];
    return sum;
}

void solve(){
    ll n, q, l, r;
    cin>>n>>q;
    ll a[n];
    fr(i, n) cin>>a[i];

    while(q--){
        cin>>l>>r;
        update(l, 1ll);
        update(r + 1ll, -1ll);
    }

    ll cnt[n];
    fr(i, n){
        cnt[i] = get(i + 1);
    }

    sort(a, a+n);
    sort(cnt, cnt+n);

    ll res = 0ll;
    fr(i, n) res += a[i]*cnt[i];

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

