#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
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

#define INF mod

void solve(){
    int n;
    cin>>n;
    pli a[n];
    fr(i, n) {
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a, a+n);

    ll dp[n+1]; /// dp[i] stores answer for first i students
    dp[0] = 0ll;
    rep(i, 1, n) dp[i] = INF;
    int p[n+1]; /// p[i] stores the index of start of segment to the end of i-1
    fr(i, n+1) p[i] = 0;
    p[0] = -1;

    rep(i, 3, n) {
        if (dp[i-3] - a[i-3].first + a[i-1].first < dp[i]) {
            p[i] = i-3;
            dp[i] = dp[i-3] - a[i-3].first + a[i-1].first;
        }

        if (i >= 4 && dp[i-4] - a[i-4].first + a[i-1].first < dp[i]) {
            p[i] = i-4;
            dp[i] = dp[i-4] - a[i-4].first + a[i-1].first;
        }

        if (i >= 5 && dp[i-5] - a[i-5].first + a[i-1].first < dp[i]) {
            p[i] = i-5;
            dp[i] = dp[i-5] - a[i-5].first + a[i-1].first;
        }

    }

    int res[n] = {0};
    int i = n;
    int en = n-1;
    int val = 1;
    while(p[i] != -1){
        rep(j, p[i], en){
            res[a[j].second] = val;
        }
        val++;
        en = p[i] - 1;
        i = p[i];
    }

    cout<<dp[n]<<" "<<val-1<<endl;
    fr(i, n) cout<<res[i]<<" ";

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

