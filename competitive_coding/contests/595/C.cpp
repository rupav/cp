#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef unsigned long long ll;
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

ll modularExponentiation(ll x, ll y){
    if(y==0)
        return 1ll;
    if(y == 1)
        return x;
    if(y&1){
        /// y is odd, so (x*(x^(y-1)))%p
        return (x*modularExponentiation(x, y-1ll));
    } else {
        /// y is even, so (x^(y/2))^2
        ll c = modularExponentiation(x, y/2);
        return (c*c);
    }
}

void ternary(ll n){
    int ternaryNum[64] = {0};
    ll original = n;
    int i = 0;
    int flag = -1;
    while (n) {
        ternaryNum[i] = n % 3;
        if(ternaryNum[i] == 2) flag = i;
        n = n / 3;
        i++;
    }

    if(flag != -1){
        rep(j, flag+1, i-1){
            if(ternaryNum[j] == 0){
                /// fill that by remainder
                ll x = modularExponentiation(3ll, 1ll*j);
                ll fac = x;
                rep(k, j+1, i-1){
                    fac *= 3ll;
                    if(ternaryNum[k] == 1){
                        x += fac;
                    }
                }
                cout<<x<<endl;
                return;
            }
        }
    }


    if(flag != -1){
        cout<<modularExponentiation(3ll, 1ll*i);
    } else {
        cout<<original;
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        ternary(n);
    }

    return 0;
}

