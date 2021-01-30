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
    map<int, int> mp;
    int a[n];
    set<int> s;
    fr(i, n){
        cin>>a[i];
        mp[a[i]]++;
        s.insert(a[i]);
    }

    int max_len = 0;
    int res_mid;
    int mid;
    int len(0);

    for(auto it: s){
        if(mp[it] > 1){
            /// wrap
            len = mp[it - 1] + mp[it + 1] + mp[it];
        } else {
            len = max(mp[it - 1], mp[it + 1]) + 1;
        }
        if(len > max_len){
            max_len = len;
            res_mid = it;
        }
    }


    cout<<max_len<<endl;
    fr(i, mp[res_mid - 1]) cout<<res_mid - 1<<" ";
    cout<<res_mid<<" ";
    fr(i, mp[res_mid + 1]) cout<<res_mid + 1<<" ";
    fr(i, mp[res_mid] - 1) cout<<res_mid<<" ";

}

int main(){
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

