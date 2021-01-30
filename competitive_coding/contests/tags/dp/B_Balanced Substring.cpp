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

ll conv(char n){
    if(n == '0') return -1ll;
    return 1ll;
}

int main(){
    ll n;
    string s;
    cin>>n>>s;
    ll pref[n+1] = {0};
    pref[0] = 0;

    rep(i, 1, n) pref[i] = pref[i-1] + conv(s[i-1]);
    map<ll, ll> mp;
    mp[0ll] = 0;
    ll ans = 0;

    rep(i, 1, n){
        if(pref[i] == 0ll) ans = i;
        else{
            if(mp.find(pref[i]) != mp.end()){
                ans = max(ans, i - mp[pref[i]]);
            } else {
                mp[pref[i]] = i;
            }
        }
    }
    cout<<ans;
    return 0;
}
