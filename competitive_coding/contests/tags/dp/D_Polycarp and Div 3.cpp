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

int main(){
    string s;
    cin>>s;
    ll n = s.size();
    ll pref[n+1] = {0};
    rep(i, 1, n) pref[i] = pref[i-1] + 1ll*(a[i-1] - '0');

    ll cuts = 0ll;
    ll dp[n+1] = {0};     /// dp[i] is the answer for string s[0....i-1], greedy approach, whenever cut possible, make it
    rep(i, 1, min(n, 3)){

    }

    return 0;
}
