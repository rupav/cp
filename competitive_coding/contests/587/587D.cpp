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

int gcdi(int a, int b){
    if(!b) return a;
    return  gcdi(b, a%b);
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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    ll a[n];
    ll max_ = 0ll;
    fr(i, n){
        cin>>a[i];
        max_ = max(max_, a[i]);
    }

    fr(i, n) a[i] = max_ - a[i];

    ll gcd = 0ll;
    fr(i, n) {
        if(a[i]) {
            gcd = a[i];
            break;
        }
    }

    if(!gcd) {
        cout<<0<<" "<<0;
        return 0;
    }


    fr(i, n){
        if(a[i] != 0ll) gcd = gcdll(a[i], gcd);
    }

    ll x = 0;
    fr(i, n) x+=a[i];
    cout<<x/gcd<<" "<<gcd;

    return 0;
}

