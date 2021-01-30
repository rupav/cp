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


/// this question translates into finding a binary tree whose leaves are the n slimes, and the sum of all internal nodes is minimum

const int nax = 405;
ll dp[nax][nax];
/// dp[i][j] = min cost of combining interval a[i...j]

void min_self(ll &a, ll b){
    a = min(a, b);
}

const ll inf = 1e18L + 5;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);

    fr(i, n) {
        cin>>a[i];
    }

    /// inline function
    auto sum = [&](int L, int R){
        ll s = 0;
        for(int i = L; i <= R; i++)
            s += a[i];
        return s;
    };

    for(int L = n - 1; L >= 0; L--){
        dp[L][L] = 0ll;
        for(int R = L + 1; R < n; R++){
            dp[L][R] = inf;
            ll s = sum(L, R);
            for(int K = L; K < R; K++){
                min_self(dp[L][R], dp[L][K] + dp[K+1][R] + s);
            }
        }
    }

    cout<<dp[0][n-1];
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

