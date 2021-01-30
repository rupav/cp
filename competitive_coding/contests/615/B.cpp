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

bool comp(pii a, pii b){
    return a.second > b.second;
}

void solve(){
    int n;
    cin>>n;
    vector<pii> co(n);
    map<int, set<int>> mp;
    fr(i, n) {
        cin>>co[i].first>>co[i].second;
        mp[co[i].second].insert(co[i].first);
    }
    // sort(co.begin(), co.end());

    int l = 0, b = 0;
    string res = "";
    bool fl = false;
    for(auto row: mp){
        fl = false;
        for(auto it: row.second){
            if(it < l){
                cout<<"NO"<<endl;
                return;
            }
            if(!fl){
                rep(i, l, it-1){
                    res += "R";
                }
                l = it;
                rep(i, b, row.first-1){
                    res += "U";
                }
                b = row.first;
                fl = true;
            } else {
                rep(i, l, it-1){
                    res += "R";
                }
                l = it;
            }
        }
    }
    cout<<"YES"<<endl;
    cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

