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

int solve(){
    int n;
    cin>>n;
    string s;
    map<pii, vector<int>> mp;
    fr(i, n){
        cin>>s;
        mp[{s[0], s[s.size()-1]}].push_back(i+1);
    }
    vector<int> ans;
    int d = (mp[{0, 1}].size() - mp[{1, 0}].size());
    if(abs(d) >= 1){
        if(d>0){
            fr(i, d-1){
                ans.push_back(mp[{0, 1}][i]);
            }
        } else {
            fr(i, d-1){
                ans.push_back(mp[{1, 0}][i]);
            }
        }
    } else {
        /// 01, 10, equal size
        if(mp[{0, 0}].size() < mp[{1, 1}].size()){
            int x = mp[{0, 0}].size();
            fr(i, x){
                ans.push_back(mp[{0, 0}][i]);
            }
        } else {
            int x = mp[{1, 1}].size();
            fr(i, x){
                ans.push_back(mp[{1, 1}][i]);
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }

    return 0;
}

