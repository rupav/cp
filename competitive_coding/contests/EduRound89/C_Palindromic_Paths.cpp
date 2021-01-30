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


void solve(){
    int n, m;
    cin>>n>>m;
    int a[n+1][m+1];
    rep(i, 1, n) rep(j, 1, m) cin>>a[i][j];

    map<int, pii> mp;   /// 0 and 1 count on diaganols
    set<int> sums;
    rep(i, 1, n){
        rep(j, 1, m){
            sums.insert(i + j);
            if(a[i][j])
                mp[i + j].first++;
            else
                mp[i + j].second++;
        }
        
    }

    int ans = 0;
    int cnt = 0;

    while((int)sums.size()){
        auto it = sums.begin();
        auto jit = sums.rbegin();
        if(*it != *jit){
            cnt = min(mp[*it].first + mp[*jit].first, mp[*it].second + mp[*jit].second);
            ans += cnt;
            sums.erase(it);
            sums.erase(sums.find(*jit));
        } else {
            // cnt = min(mp[*it].first, mp[*it].second);
            // ans += cnt;
            sums.erase(it);
        }
    }

    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

