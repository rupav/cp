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

map<pll, ll> mp;

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    mp.clear();

    ll vert[n+1] = {0}, horz[n+1] = {0};
    ll min_ = mod;
    ll a = 0, b = 0;
    pll p;
    mp[{0, 0}] = 0;

    rep(i, 1, n){
        vert[i] = vert[i-1];
        horz[i] = horz[i-1];

        if(s[i-1] == 'L' || s[i-1] == 'R'){
            if(s[i-1] == 'L') horz[i]--;
            else horz[i]++;
        } else {
            if(s[i-1] == 'D') vert[i]--;
            else vert[i]++;
        }

        p = {horz[i], vert[i]};
        if(mp.find(p) != mp.end()){
            min_ = min(min_, i - mp[p]);
            if(min_ == i - mp[p]){
                a = mp[p]+1;
                b = i;
            }
        }

        mp[{horz[i], vert[i]}] = i;
    }

    if(a) cout<<a<<" "<<b;
    else cout<<-1;

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

