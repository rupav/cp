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


void solve_2(){
    int n;
    cin>>n;
    vector<int> dp(3, 0);
    fr(day, n){
        vector<int> c(3), new_dp(3, 0);
        fr(j, 3) cin>>c[j];

        fr(i, 3){
            fr(j, 3){
                if(i != j){
                    new_dp[j] = max(new_dp[j], c[j] + dp[i]);
                }
            }
        }
        dp = new_dp;
    }

    cout<<(*max_element(dp.begin(), dp.end()));
}


void solve(){
    ll n;
    cin>>n;
    ll a[n], b[n], c[n];
    ll a_, b_, c_;  /// value of happiness at ith day, if activity was done A, B and C resp
    fr(i, n) cin>>a[i]>>b[i]>>c[i];

    a_ = a[0], b_ = b[0], c_ = c[0];
    ll ta, tb, tc;  /// temp vars
    rep(i, 1, n-1){
        ta = a[i] + max(b_, c_);
        tb = b[i] + max(a_, c_);
        tc = c[i] + max(b_, a_);

        a_ = ta, b_ = tb, c_ = tc;
    }
    cout<<max({a_, b_, c_});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve_2();
    }

    return 0;
}

