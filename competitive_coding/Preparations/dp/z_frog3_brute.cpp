#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;
const ll INF = 1e18L + 5;

void min_self(ll &a, ll b){
    a = min(a, b);
}

void solve(){
    ll n, c, x;
    cin>>n>>c;
    vector<ll> dp(n, INF);
    dp[0] = 0;
    vector<ll> ht(n);
    fr(i, n){
        cin>>ht[i];
    }

    fr(i, n){
        rep(j, i+1, n - 1){
            min_self(dp[j], c + sq(ht[j] - ht[i]) + dp[i]);
        }
    }

    cout<<dp[n-1];

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

