/// Flood Fill. - make all components with equal color. - Idea is that to first compress the array, and use the fact that final solution always has the color of either of its ends!
#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int dp[5002][5002];

int solve(int l, int r, int dp[5002][5002], vector<int> c){
    int &ret = dp[l][r];
    if(ret != -1)
        return ret;
    if(l>=r)
        return ret = 0;
    if(c[l] == c[r]){
        /// It is gauranteed in compressed array that color of component c[l+1...r-1] is either c[l+1](not eqaul to c[l]) or c[r-1](not equal to c[r])
        return ret = 1 + solve(l+1, r-1, dp, c);
    } else {
        return ret = min(1+solve(l+1, r, dp, c), 1+solve(l, r-1, dp, c));
    }
}

int main(){
    int n;
    cin>>n;
    int c[n];
    vector<int> compressed;
    int prev = INT_MAX;
    fr(i, n){
        cin>>c[i];
        if(c[i]!=prev){
            compressed.push_back(c[i]);
            prev = c[i];
        }
    }
    int m = compressed.size();
    fr(i, m){
        fr(j, m){
            /// initialization with -1, indicating not visited!
            dp[i][j] = 0;
        }
    }

    rep(j, 1, m-1){
        for(int i=j-1; i>=0; i--){
            if(compressed[i] == compressed[j]){
                dp[i][j] = 1+dp[i+1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i][j-1], dp[i+1][j]);
            }
        }
    }

    cout<<dp[0][m-1];

    return 0;
}
