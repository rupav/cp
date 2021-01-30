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

    ll n, l, x, min_, max_, res=0ll;
    cin>>n;
    vector<vector<ll>> a(n);
    fr(i, n){
        cin>>l;
        fr(j, l){
            cin>>x;
            a[i].push_back(x);
        }
    }

    vector<ll> v[2];  /// min_, and max_
    fr(i, n){
        min_ = a[i][0];
        max_ = a[i][0];
        l = a[i].size();
        bool f = false;
        rep(j, 1, l-1){
            if(a[i][j] > min_){
                res += 1ll*n;
                f = true;
                break;
            }
            min_ = min(min_, a[i][j]);
            max_ = max(max_, a[i][j]);
        }
        if(!f){
            v[0].push_back(min_);
            v[1].push_back(max_);
            if(min_ != max_){

            }
        }
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());

    ll m = v[0].size();
    for(auto it: v[0]){
        auto ub = upper_bound(v[1].begin(), v[1].end(), it)  - v[1].begin();
        // cout<<ub<<endl;
        res += (m - ub) + (n-m);
    }
    cout<<res;

    return 0;
}

