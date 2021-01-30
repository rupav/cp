#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 998244353;

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}

ll modularExponentiation(ll x, ll y, ll p){
    if(x == 0) return 0ll;
    if(y == 0) return 1ll;
    if(y&1ll){
        return (x*modularExponentiation(x, y-1, p))%p;
    }
    ll temp = modularExponentiation(x, y/2, p)%p;
    return (temp*temp)%p;
}

ll inverse(ll x){
    return modularExponentiation(x, mod-2, mod);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<ll, ll> mp;
    int n;
    cin>>n;
    vector<vector<ll>> v(n);
    int k, x;
    fr(i, n){
        cin>>k;
        fr(j, k){
            cin>>x;
            v[i].push_back(x);
            mp[x]++;
        }
    }
    ll val = inverse(n);
    ll ans = 0ll;
    fr(i, n){
        ll vali = inverse(v[i].size());
        ll cnt = 0;
        for(auto it: v[i]){
            cnt = (cnt + (val*mp[it])%mod)%mod;
        }
        ans = (ans + (vali*cnt)%mod)%mod;
    }
    cout<<(ans*val)%mod;

    return 0;
}

