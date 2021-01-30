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

bool solve(){
    ll l[2], u[2];
    fr(i, 2) cin>>l[i];
    fr(i, 2) cin>>u[i];

    ll rt, ut;
    rt = l[1] - l[0];
    ut = u[1] - u[0];

    ll x, y;
    cin>>x>>y;
    ll x_[2], y_[2];
    fr(i, 2) {
        cin>>x_[i];
        cin>>y_[i];
    }

    ll d, z, t;

    if(l[0] > l[1]){
        d = x - x_[0];
        z = x_[1] - x;
        t = l[0];
        l[0] = l[1];
        l[1] = t;
        x_[0] = x - z;
        x_[1] = x + d;
    }

    if(u[0] > u[1]){
        d = y - y_[0];
        z = y_[1] - y;
        t = u[0];
        u[0] = u[1];
        u[1] = t;
        y_[0] = y - z;
        y_[1] = y + d;
    }

    /// min is left
        l[0] -= x - x_[0];
        if(l[0]) l[1] -= l[0];
        l[0] = 0;
        x = x_[0];
        if(l[1] > x_[1] - x) return false;

        u[0] -= y - y_[0];
        if(u[0]) u[1] -= u[0];
        u[0] = 0;
        y = y_[0];
        if(u[1] > y_[1] - y) return false;

        return true;

    /// go left

    d = min(l[0], x - x_[0]);
    l[0] -= d;
    x -= d;
    d = min(l[1], x_[1] - x);
    l[1] -= d;
    x += d;
    d = min(l[0], x - x_[0]);
    l[0] -= d;

    if(l[0] || l[1]) return false;

    d = min(u[0], y - y_[0]);
    u[0] -= d;
    y -= d;
    d = min(u[1], y_[1] - y);
    u[1] -= d;
    y += d;
    d = min(u[0], y - y_[0]);
    u[0] -= d;


    if(u[0] || u[1]) return false;

    return true;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "YES": "NO")<<endl;
    }

    return 0;
}


