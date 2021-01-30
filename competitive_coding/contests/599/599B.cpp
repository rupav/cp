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

void solve(){
    int n;
    cin>>n;
    string s, t;
    cin>>s;
    cin>>t;

    map<int, set<int>> mp[2];

    fr(i, n){
        if(s[i] != t[i]){
            mp[0][s[i] - 'a'].insert(i);
            mp[1][t[i] - 'a'].insert(i);
        }
    }

    map<int, int> cnt;

    for(auto it: mp[0]) cnt[it.first] += it.second.size();

    for(auto it: cnt){
        if(cnt&1) {
            cout<<"NO";
            return;
        }
    }

    cout<<"YES"<<endl;
    vector<pii> ans;
    int m = 0;
    for(i=0; i<26; i++){
        while(mp[0][i].size() && mp[1][i].size()){
            auto it0 = mp[0][i].begin();
            auto it1 = mp[1][i].begin();
            ans.push_back({*it0, *it0});
            ans.push_back({*it0, *it1});
            mp[0][i].erase(*it0);
            mp[1][i].erase(*it1);

        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--){
        solve();
        cout<<endl;
    }

    return 0;
}

