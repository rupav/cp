
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

bool solve_(){
    ll n, d;
    cin>>n>>d;
    ll st = 1ll, en = d;
    if(d <= n) return true;
    while(st < en){
        ll x = (st + en)>>1;
        ll t = x + d/(x+1) + ((d%(x+1)) != 0);
        if(t <= n) return true;
        en = x;
        x = d - x;
        t = x + d/(x+1) + ((d%(x+1)) != 0);
        if(t <= n) return true;
    }
    return false;
}

bool solve(){
    ll n, d;
    cin>>n>>d;
    if(d <= n) return true;
    ll max_ = d+1;
    ll t;
    ll x = 0ll;
    while(x < d){
        ll t = x + d/(x+1) + ((d%(x+1)) != 0);
        if(t <= n) return true;
        if(t > max_) break;
        max_ = t;
        x++;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cout<<(solve() ? "YES" : "NO")<<endl;
    }

    return 0;
}
