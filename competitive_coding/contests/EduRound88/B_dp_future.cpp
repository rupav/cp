#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

const int INF = INT_MAX;
const int nax = 1e3 + 5;
vector<int> dp(nax);

void min_self(int &a, int b){
    a = min(a, b);
}

void solve(){
    int n, m, x, y;
    cin>>n>>m>>x>>y;
    dp.assign(m+1, INF);
    dp[0] = 0;

    for(int i = 0; i < m; i++){
        if(i + 1 <= m) min_self(dp[i + 1], dp[i] + x);
        if(i + 2 <= m) min_self(dp[i + 2], dp[i] + y);
    }


    int cost = 0ll;

    string s;
    int st, en, j, k;
    fr(i, n){
        cin>>s;
        j = 0;
        while(j < m){
            if(s[j] == '.'){
                k = j + 1;
                while(k < m && s[k] == '.') k++;
                cost += dp[k - j];
                j = k;
            } else j++;
        }
    }

    cout<<cost<<endl;

}

signed main(){
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

