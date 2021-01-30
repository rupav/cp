#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

vector<ll> dp;
const ll N = 1e9+5;

void fill_(){
    ll h = 1ll;
    ll cards = 2ll;
    while(cards < N){
        dp.push_back(cards);
        h++;
        cards += 2ll*h + (h - 1ll);
    }
}

void solve(){
    ll n;
    cin>>n;
    ll ans = 0ll;
    while(true){
        auto ub = upper_bound(dp.begin(), dp.end(), n) - dp.begin();
        int pos = ub - 1;
        if(pos < 0) break;
        n -= dp[pos];
        ans++;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    fill_();
    // watch(dp.size());
    while(t--){
        solve();
    }

    return 0;
}

