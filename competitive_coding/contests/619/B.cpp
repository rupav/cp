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
    vector<int> e;
    fr(i, n) cin>>a[i];
    int diff = 0;

    fr(i, n-1){
        if(a[i] != -1 && a[i+1] != -1){
            diff = max(diff, abs(a[i] - a[i+1]));
        }
    }

    rep(i, 1, n-2){
        if(a[i] >= 0){
            if(a[i-1] == -1 || a[i+1] == -1) e.push_back(a[i]);
        }
    }
    if(a[0] != -1 && a[1] == -1){
        e.push_back(a[0]);
    }
    if(a[n-1] != -1 && a[n-2] == -1){
        e.push_back(a[n-1]);
    }

    sort(e.begin(), e.end());
    int m = e.size();
    if(!m){
        cout<<diff<<" "<<0;
        return;
    }

    int k = (e[0] + e[m-1])/2;
    diff = max(diff, max(abs(e[0] - k), abs(e[m-1] - k)));

    cout<<diff<<" "<<k;
    return;

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

