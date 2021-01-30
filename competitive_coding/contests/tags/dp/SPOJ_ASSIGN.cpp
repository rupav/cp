#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
const int N = 25;
int ALL_PERSON;
ll dp[1050000][22];
bool arr[N][N];

ll calc(int mask, int aid, int n){
    if(mask == ALL_PERSON){
        return 1;
    }
    if(aid > n){
        return 0;
    }
    if(dp[mask][aid] != -1)
        return dp[mask][aid];

    ll &ans = dp[mask][aid];
    ans = 0;

    for(int i=1; i<=n; i++){
        if(arr[i][aid] == true){
            i--;
            if(((mask) & (1<<i)) == 0){
                ans += calc((mask|(1<<i)), aid+1,  n);
            }
            i++;  // avoid infinite loop.
        }
    }

    return ans;

}

int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        memset(dp, -1, sizeof(dp));
        ALL_PERSON = (1<<n) - 1;
        int temp;
        rep(i, 1, n){
            rep(j, 1, n){
                cin>>temp;
                arr[i][j] = (bool) temp;
            }
        }
        cout<<calc(0, 1, n)<<endl;
    }
    return 0;
}

