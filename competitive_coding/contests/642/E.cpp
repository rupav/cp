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


int solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt[k] = {0};
    fr(i, n){
        cnt[i%k] += (s[i] == '1');
    }

    int tot = accumulate(cnt, cnt + k, 0);

    int dp[n] = {0};    /// min with this last light on

    int temp;
    fr(i, n){
        int &z = dp[i];

        temp = (s[i] == '0') ? 1 : -1;
        z = cnt[i%k] + temp;  /// switch only this
        if(i - k >= 0){
            temp = (s[i] == '0') ? 1 : -1;
            z = min(z, dp[i - k] + temp);
        }
    }

    int ans = tot;
    fr(i, n) ans = min(ans, dp[i] + (tot - cnt[i%k]));

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

