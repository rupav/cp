#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
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

int solve(){
    int n, st;
    cin>>n>>st;
    int mid = n/2 + (n&1);
    if(st > mid) st = n - st + 1;   /// bring in the first half
    char a[n + 1];
    rep(i, 1, n) cin>>a[i];

    int l = 0, r = 0;
    int res = 0;
    rep(i, 1, mid){
        if(a[i] == a[n-i+1]) continue;
        res += min(abs(a[i] - a[n-i+1]),
                   min(a[i] - 'a', a[n-i+1] - 'a') + 'z' - 'a' - max(a[i] - 'a', a[n-i+1] - 'a') + 1);
        if(!l) l = i;
        r = i;
    }

    if(!l) return 0;

    // watch(res);
    // watch(r);
    // watch(l);

    int p = st;
    return res + abs(r - l) + min(abs(p - r), abs(p - l));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        cout<<solve();
    }

    return 0;
}
