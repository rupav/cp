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
int mod = 1e9+7;

void add_self(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}

void sub_self(int &a, int b){
    a -= b;
    if(a < 0) a += mod;
}

void solve(){
    int n, k;
    cin>>n>>k;
    int a[n+1];

    vector<int> dp(k+1);    /// dp[i] = no. of ways to share i candies among children considered so far.
    dp[0] = 1;

    for(int child = 0; child < n; ++child){
        int ub;
        cin>>ub;
        vector<int> fake(k+1);
        for(int used = k; used >=0; --used){
            int temp = dp[used];
            int L = used + 1;
            int R = used + min(k - used, ub);
            if(L <= R){
                add_self(fake[L], temp);
                if(R+1 <= k)
                    sub_self(fake[R+1], temp);
            }
            /*
                for(int i=L; i<=R; i++){
                    add_self(dp[i], temp);  /// range update from L to R with temp, we can use BIT to do that, instead use pref sum concept
                }
            */
        }
        int prefix_sum = 0;
        for(int i=0; i<=k; i++){
            add_self(prefix_sum, fake[i]);
            add_self(dp[i], prefix_sum);
        }
    }

    cout<<dp[k];

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

