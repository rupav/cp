/// https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/special-pairs-7/description/
/// finding count of pairs for which a&b is 0.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define LIM 20
#define fr(i, n) for(int i=0; i<n; i++)

ll dp[1ll*(1<<LIM)][LIM];  /// based on sos dp idea
vector<ll> f(1ll*(1<<LIM));

void fill_pairs(int N = LIM){
    for(ll mask=0; mask < (1<<N); mask++){
        dp[mask][0] = f[mask];  /// frequency of that mask, and its submask
        if(mask&1) dp[mask][0] += f[mask^1];
        for(int i=1; i<N; i++){
            dp[mask][i] = dp[mask][i-1];
            if(mask&(1<<i))
                dp[mask][i] += dp[mask^(1<<i)][i-1];
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        f.assign((1<<20), 0ll);
        fr(i, n){
            cin>>a[i];
            f[a[i]]++;
        }
        memset(dp, 0, sizeof(dp));
        fill_pairs(20);  /// N*2^N approach for each test case, here N is 20 only
        ll ans = 0;
        fr(i, n){
            ans += 1ll*dp[(1<<20) - 1 - a[i]][19];
        }
        cout<<ans<<endl;
    }
    return 0;
}
