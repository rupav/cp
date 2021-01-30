/// subset over sum DP, N*2^N time complexity
/// reference - https://codeforces.com/blog/entry/45223

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[2000][10];  /// 2^10; 10
ll F[2000];

/* example
                11, 1

    11, 0                 01, 0

11          10      00              01
*/

void sos(int N){

    memset(dp, sizeof(dp), 0);
    memset(F, sizeof(F), 0);

    for(int mask = 0; mask < (1<<N); mask++){
        dp[mask][0] = (mask&1) ? 1ll*mask + 1ll*(mask-1) : 1ll*mask;
        for(int i=1; i<N; i++){
            if(mask & (1<<i)){
                dp[mask][i] = dp[mask][i-1] + dp[mask^(1<<i)][i-1];
            } else {
                dp[mask][i] = dp[mask][i-1];
            }
        }
        F[mask] = dp[mask][N-1];
    }
}

int main(){
    sos(10);
    int i;
    while(i != -1){
        cin>>i;
        cout<<F[i]<<endl;
    }
    return 0;
}
