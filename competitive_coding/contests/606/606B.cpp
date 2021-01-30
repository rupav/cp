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



ll solve(){
    int n;
    cin>>n;
    ll a[n];
    fr(i, n) cin>>a[i];
    sort(a, a+n);
    ll cnt = 0;
    vector<ll> v;
    map<ll, bool> mp;
    for(int i=n-1; i>=0;){
        if(a[i]%2 == 0){
            v.push_back(a[i]);
            mp[a[i]] = true;
        }
        int j=i-1;
        while(j>=0 && a[j]==a[i]){
            j--;
        }
        i = j;
    }

    fr(i, v.size()){
        if(mp[v[i]]){
            mp[v[i]] = false;
            int d = 0;
            while(!(v[i]&1ll)){
                v[i] = v[i]>>1;
                d++;
                mp[v[i]] = false;
            }
            cnt+=1ll*d;
        }
    }
    return cnt;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cout<<solve();
        cout<<endl;
    }

    return 0;
}

