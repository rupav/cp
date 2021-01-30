#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
#define int ll
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
    int n, k, p, q, x;
    cin>>n>>k>>p;
    q = k - p;
    int cnt[2] = {0};
    vector<int> v[2];
    fr(i, n) {
        cin>>x;
        v[x&1].push_back(x);
    }

    int sz[2] = {(int)v[0].size(), (int)v[1].size()};
    if(sz[1] < q || ((sz[1] - q)&1)) {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    fr(i, q) cout<<1<<" "<<v[1][i]<<endl;

    /// now p subsets with even sum left
    fr(i, p - 1) cout<<1<<" "<<v[0][i]<<endl;
    cout<<(sz[0] - p + 1 + sz[1] - q)<<" ";
    rep(i, p - 1, sz[0] - 1) cout<<v[0][i]<<" ";
    rep(i, q, sz[1] - 1) cout<<v[1][i]<<" ";
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

