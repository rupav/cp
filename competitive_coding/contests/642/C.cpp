#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

const int nax = 5e5 + 5;
ll dp[nax];
ll c[nax];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    dp[1] = 0ll;
    c[1] = 0ll;
    ll cnt;
    ll one;
    for(ll i = 3; i < nax; i += 2ll){
        cnt = (i - 1ll)*4ll;
        c[i] = i/2ll;
        dp[i] = dp[i - 2ll] + cnt*c[i];
    }


    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<dp[n]<<endl;
    }

    return 0;
}

