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
#define INF INT_MAX

/// https://www.codechef.com/LTIME84A/problems/CHEFZRON

int solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> ones;
    ones.push_back(0);
    rep(i, 1, n) {
        cin>>a[i];
        if(a[i]) ones.push_back(i);
    }

    int m = ones.size();
    if(m == 1) return 0;
    if(m == 2) return -1;

    int ans = n;
    int iter = 0;

    do{
        vector<int> dp(m, 0);
        dp[1] = n + 1;
        rep(i, 2, m - 1){
            dp[i] = dp[i - 2] + ones[i] - ones[i - 1];
            if(i >= 3) dp[i] = min(dp[i], dp[i - 3] + ones[i] - ones[i - 2]);
        }


        ans = min(ans, dp[m - 1]);
        iter++;

        /// rotate ones
        int x = ones[1];
        rep(i, 1, m - 2) ones[i] = ones[i + 1] - x;
        ones[m - 1] = n;
    } while(iter <= 2);

    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

