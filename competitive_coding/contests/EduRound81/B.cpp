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

const int N = 2e5 +10;
ll pref[N];

void calc(string &s, int n){
    rep(i, 1, n) pref[i] = 0;
    pref[0] = 0ll;
    rep(i, 1, n){
        if(s[i-1] == '1') pref[i] = pref[i-1] + 1;
        else pref[i] = pref[i-1] - 1;
    }
    return;
}

ll solve(){
    ll n, x;
    cin>>n>>x;
    string s;
    cin>>s;

    if(x >= 0ll){
        fr(i, n){
            if(s[i] == '1') s[i] = '0';
            else s[i] = '1';
        }
    } else {
        x *= -1ll;
    }

    calc(s, n);
    ll bal_n = pref[n];

    if(bal_n == 0){
        rep(i, 1, n){
            if(pref[i] == x) return -1;
        }
        return 0;
    }

    // check if j = (i mod n), bal(j) + k.bal_n == x, for each j from 0 to n-1, k is no. of competed cycles
    ll cnt = 0ll;
    rep(j, 0, n-1){
        if((x - pref[j])%bal_n == 0 && (x - pref[j])/bal_n >= 0ll){
            cnt++;
        }
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cout<<solve();
        cout<<endl;
    }

    return 0;
}

