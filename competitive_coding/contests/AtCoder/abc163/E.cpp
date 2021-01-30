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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

void solve(){
    ll n;
    cin>>n;
    pll a[n];
    fr(i, n) {
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a, a+n, greater<pll>());

    ll res = 0ll;
    ll st = 0, en = n-1, pos;

    map<pii, ll> mp;    /// ans
    mp[{0, n}] = a[0].first*(llabs(a[0].second - 0));   /// placing in the start
    mp[{-1, n-1}] = a[0].first*(llabs(a[0].second - n + 1));    /// placing in the last

    rep(i, 1, n-1){
        map<pii, ll> tmp;   /// temp map

        for(auto it: mp){
            /// there are 2 choices to place new element for this pair
            st = it.first.first + 1;
            en = it.first.second - 1;


            if(st + n - 1 - en != i) continue;


            tmp[{st, en + 1}] = max(tmp[{st, en + 1}], it.second + a[i].first*(llabs(a[i].second - st)));
            tmp[{st - 1, en}] = max(tmp[{st - 1, en}], it.second + a[i].first*(llabs(a[i].second - en)));
        }

        mp = tmp;
    }

    ll ans = 0;

    for(auto it: mp){
        ans = max(ans, it.second);
    }

    cout<<ans;

}

const int N = 2005;
ll dp[N][N] = {};

void solve_dp(){
    ll n;
    cin>>n;
    pll a[n+1];
    rep(i, 1, n){
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a+1, a+n+1, greater<pll>());

    int L, R;
    rep(i, 1, n){
        ll pos = a[i].second;
        fr(j, i){
            L = j;
            R = i - 1 - L;  /// total elements filled are i - 1
            dp[L+1][R] = max(dp[L+1][R], dp[L][R] + llabs(L + 1 - pos)*a[i].first);

            R = j;
            L = i - 1 - R;
            dp[L][R+1] = max(dp[L][R+1], dp[L][R] + llabs(n - R - pos)*a[i].first);
        }
    }

    ll ans = 0;
    rep(i, 0, n){
        ans = max(ans, dp[i][n-i]);
    }

    cout<<ans;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve_dp();
    }

    return 0;
}

