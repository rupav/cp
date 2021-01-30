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


void solve(){
    int n;
    cin>>n;
    int a[n+1];
    rep(i, 1, n) cin>>a[i];

    vector<int> dp(n+1, 1);

    rep(i, 2, n){
        for(int j = 1; j*j <= n; j++){
            if(i%j == 0){
                if(a[i] > a[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if(a[i] > a[i/j]){
                    dp[i] = max(dp[i], dp[i/j] + 1);
                }
            }
        }
    }

    cout<<*max_element(dp.begin() + 1, dp.end())<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

