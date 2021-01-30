#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<string, string>> vss;
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
    int n, m;
    cin>>m>>n;
    vector<string> v(m);

    fr(i, m){
        cin>>v[i];
    }

    vector<string> fr, ba;
    map<string, bool> mp;

    for(auto s: v){
        reverse(s.begin(), s.end());
        if(mp[s]){
            fr.push_back(s);
            mp.erase(mp.find(s));
            reverse(s.begin(), s.end());
            ba.push_back(s);
        } else {
            reverse(s.begin(), s.end());
            mp[s] = true;
        }
    }

    string q = "";
    int len = 0;
    for(auto s: mp){
        string t = s.first;
        reverse(t.begin(), t.end());
        if(t == s.first && t.size() > len){
            q = s.first;
            len = t.size();
        }
    }

    string res = "";
    for(auto it: fr){
        res += it;
    }
    res += q;
    reverse(ba.begin(), ba.end());
    for(auto it: ba) res += it;

    cout<<res.size()<<endl;
    cout<<res;

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

