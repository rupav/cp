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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin>>n>>m;
    ll a[n], b[n];
    fr(i, n) cin>>a[i];
    fr(i, n) cin>>b[i];

    sort(a, a+n);
    sort(b, b+n);
    /// brute
    ll ans = m;

    map<ll, bool> mp2;
    map<ll, ll> mp3;
    vector<int> temp(n);

    fr(i, 1){
        if(true){
            /// find all possible x
            fr(j, n){
                ll x = (b[j] + m - a[i])%m;
                if(!mp2[x]){
                    /// find if correct
                    mp3.clear();
                    fr(k, n){
                        temp[k] = (a[k]+x)%m;
                        mp3[temp[k]]++;
                    }

                    bool fl = true;
                    fr(k, n){
                        if(!mp3[b[k]]) {
                            fl = false;
                            break;
                        }
                        mp3[b[k]]--;
                    }
                    if(fl){
                        ans = min(ans, x);
                    }
                }
                mp2[x] = true;
            }
        }
    }
    cout<<ans;

    return 0;
}

