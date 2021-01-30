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


vector<ll> dp;
vector<ll> pre; /// preprocessing
const int nax = 16;
ll cap[nax][nax];

const ll inf = 1e18L + 5;


void rec(int i, vector<int>& not_taken, int mask, ll sum_so_far, int group){
    if(i == (int)not_taken.size()){
        dp[mask] = max(dp[mask], sum_so_far + pre[group]);
        return;
    }

    rec(i + 1, not_taken, mask, sum_so_far, group);
    rec(i + 1, not_taken, mask ^ (1<<not_taken[i]),
        sum_so_far, group ^ (1<<not_taken[i]));
}


void solve(){
    int n;
    cin>>n;
    dp.resize((1<<n), -inf);
    pre.resize((1<<n));
    /// dp[mask] - maximum possible total score with rabbits in mask already being grouped
    /// pre[mask] - total score with all rabbits in the mask in 1 group
    dp[0] = 0;
    fr(i, n){
        fr(j, n){
            cin>>cap[i][j];
        }
    }

    for(int mask = 0; mask < (1<<n); ++mask){
        for(int i=0; i<n; i++){
            if(mask & (1<<i)){
                for(int j=i+1; j<n; j++){
                    if(mask & (1<<j)){
                        pre[mask] += cap[i][j];
                    }
                }
            }
        }
    }

    for(int mask = 0; mask < (1<<n); ++mask){
        vector<int> not_taken;
        for(int i=0; i<n; i++){
            if(!(mask & (1<<i)))
                not_taken.push_back(i);
        }

        /// recurse over different possible combinations of putting elements among not_taken rabbits in 1 group
        rec(0, not_taken, mask, dp[mask], 0);
    }

    cout<<dp[(1<<n) - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}

