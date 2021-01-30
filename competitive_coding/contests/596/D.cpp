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

vector<int> prime;

ll modularExponentiation(ll x, ll y){
    if(y==0)
        return 1;
    if(y == 1)
        return x;
    if(y&1){
        /// y is odd, so (x*(x^(y-1)))%p
        return min(1ll*INT_MAX, (x*modularExponentiation(x, y-1)));
    } else {
        /// y is even, so (x^(y/2))^2
        ll c = modularExponentiation(x, y/2);
        return min(1ll*INT_MAX, (c*c));
    }
}

void seive(int n = 100005){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    int cnt = 0;
    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            cnt++;
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(is_prime[i]) prime.push_back(i);
    }
}

vector<int> v;

int factorize(int x, int k){
    int cnt = 0;
    int val = 1;

    for(auto p: prime){
        if(x == 1) break;
        cnt = 0;
        while(x%p == 0){
            cnt++;
            x /= p;
        }
        val *= modularExponentiation(p, cnt%k);
    }

    return val;
}

int max_ = INT_MAX;

int fact(int x, int k){
    int cnt = 0;
    int val = 1;

    for(auto p: prime){
        if(x == 1) break;
        cnt = 0;
        while(x%p == 0){
            cnt++;
            x /= p;
        }
        if(cnt)
            val *= modularExponentiation(p, k-cnt);
        if(val > max_) return -1;
    }
    return val;
}

map<int, int> mp;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    seive();
    int n, k;
    cin>>n>>k;
    v.resize(n);
    fr(i, n){
        cin>>v[i];
        v[i] = factorize(v[i], k);
        mp[v[i]]++;
    }


    ll cnt = 0;
    sort(v.begin(), v.end());
    auto it = upper_bound(v.begin(), v.end(), 1);
    max_ = v[n-1];


    ll temp = 0;
    if(it == v.end()){
        cnt = (1ll*n*1ll*(n-1))/2;
    } else {
        int pos = it - v.begin();
        cnt = (1ll*pos*1ll*(pos-1))/2;
        rep(i, pos, n-1){
            int z = fact(v[i], k);
            if(z == v[i]) temp += 1ll*(mp[z]) -1ll;
            else temp += 1ll*(mp[z]);
        }
        cnt += temp/2ll;
    }

    cout<<cnt;

    return 0;
}
