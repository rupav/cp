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
const int INF = INT_MAX;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    set<int> s;
    fr(i, n) {
        cin>>a[i];
        s.insert(a[i]);
    }
    map<int, int> mp;
    int val = 1;
    for(auto it: s) mp[it] = val++;
    fr(i, n) a[i] = mp[a[i]];
    int mx = *max_element(a.begin(), a.end());

    vector<int> p(mx + 1);  /// pos
    vector<int> dp(mx + 1, 1);
    fr(i, n) p[a[i]] = i;
    
    /// after removing moves, we get a segment of continuous no.s!
    int z = mx - 1;
    while(z > 0){
        if(p[z] < p[z + 1]) dp[z] = dp[z + 1] + 1;
        z--;
    }

    int len = *max_element(dp.begin(), dp.end());
    cout<<n - len<<endl;
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

