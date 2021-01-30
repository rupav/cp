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
#define int ll

const int sz = 26;
ll cnt[sz] = {0};
ll dp[sz][sz];

int conv(char x){ return (int)(x - 'a'); }

int solve(){
    string s;
    cin>>s;

    int n = s.size();
    char x;
    int val;

    memset(dp, 0, sizeof(dp));

    fr(i, n){
        x = s[i];
        val = conv(x);
        fr(j, sz) dp[j][val] += cnt[j];
        cnt[val]++;
    }

    ll res = *max_element(cnt, cnt + sz);
    fr(i, sz) fr(j, sz) res = max(res, dp[i][j]);

    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        cout<<solve();
    }

    return 0;
}

