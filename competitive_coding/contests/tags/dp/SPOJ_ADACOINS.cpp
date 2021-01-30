#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
const int N = (int)(1e9+10);

int main(){

    int n, q;
    cin>>n>>q;
    bitset<100005> bs;  /// of size 10001 bits, each bit can be accessed as bs[i] where i is from left.
    bs[0] = 1;
    int val;
    rep(i, 1, n){
        scanf("%d", &val);
        bs |= bs<<val;
    }

    /// now that we know, all subsequence sum, we need to calculate how many of them are true/1 in a given segment, this can be achieved by prefix sum.
    int sum[100005];
    sum[0] = 0;
    rep(i, 1, 100001){
        sum[i] = sum[i-1] + bs[i];
    }

    int a, b;
    while(q--){
        scanf("%d%d", &a, &b);
        printf("%d\n", sum[b]-sum[a-1]);
    }

    return 0;
}

