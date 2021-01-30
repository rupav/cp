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

void solve(){
    int n;
    cin>>n;
    int a[n];
    set<int> s;
    fr(i, n) {
        cin>>a[i];
        s.insert(a[i]);
    }
    int c[n];
    if(n%2 == 0){
        if(s.size() == 1) rep(i, 1, n) c[i] = 1;
        else rep(i, 1, n) c[i] = (i&1) + 1;
    } else {
        if(s.size() == 1) rep(i, 1, n) c[i] = 1;
        else {
            bool f = false;
            int ind = -1;
            fr(i, n-1) {
                if(a[i] == a[i+1]){
                    f = true;
                    ind = i+1;
                    break;
                }
            }
            if(!f) {
                rep(i, 1, n) c[i] = (i&1) + 1;
                c[n] = 3;
            } else {
                rep(i, 1, ind) c[i] = (i&1) + 1;
                rep(i, ind + 1, n) c[i] = !(i&1) + 1;
            }
        }
    }

    if(s.size() > 1 && n&1 && a[0] == a[n-1]){
        rep(i, 1, n) c[i] = !(i&1) + 1;
    }

    set<int> ans;
    rep(i, 1, n) ans.insert(c[i]);
    cout<<ans.size()<<endl;
    rep(i, 1, n) cout<<c[i]<<" ";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }

    return 0;
}

