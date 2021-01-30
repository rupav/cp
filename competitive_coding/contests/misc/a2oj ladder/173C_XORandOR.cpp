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
    string s, t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    if(n != m) return false;

    /// 11 maps to 01 or 10, 00 maps to 00, 01 maps to 11, 10 maps to 11
    /// to make 0 to 1 - need to find index i such that s[i] = t[i] = 1
    /// to make 1 to 0 - need to find index i such that s[i] = 0 but t[i] = 1 OR s[i] = t[i] = 1
    int cnt[2] = {0};
    bool f[2] = {false, false};
    fr(i, n) {
        if(s[i] != t[i]) {
            cnt[0]++;
            f[s[i] == '1'] = true;
        }
        if(s[i] == '1' && s[i] == t[i]) cnt[1]++;
    }
    return (!cnt[0] || cnt[1] || (f[0] && f[0] == f[1]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        cout<<(solve() ? "YES" : "NO")<<endl;;
    }

    return 0;
}

