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


int solve(int n, int k, string s){
    /*
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    */

    int cnt[k] = {0};
    fr(i, n){
        cnt[i%k] += (s[i] == '1');
    }

    int tot = accumulate(cnt, cnt + k, 0);

    int dp[n] = {0};    /// min with this last light on

    int temp;
    fr(i, n){
        int &z = dp[i];

        z = cnt[i%k] + (int)(s[i] == '0');  /// switch only this
        if(i - k >= 0){
            int temp = (s[i] == '0') ? 1 : -1;
            z = min(z, dp[i - k] + temp);
        }
        // watch(z);
    }

    int ans = n;
    fr(i, n) ans = min(ans, dp[i] + (tot - cnt[i%k]));

    return ans - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> s =
    {
        "0000",
        "0001",
        "0010",
        "0011",
        "0100",
        "0101",
        "0110",
        "0111",
        "1000",
        "1001",
        "1010",
        "1011",
        "1100",
        "1101",
        "1110",
        "1111"
    };

    for(auto it: s){
        cout<<it<<": "<<solve(4, 2, it)<<endl;
    }

    /*
    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    */

    return 0;
}


