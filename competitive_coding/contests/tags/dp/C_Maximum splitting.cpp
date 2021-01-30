#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


int solve(){
    int n;
    cin>>n;
    vector<int> dp(12, -1);
    dp[4] = dp[9] = dp[6] = 1;
    dp[8] = dp[10] = 2;

    if(n < 12) return dp[n];

    int md = n%4;

    if(!md) return n/4;

    if(md == 1) return 1 + (n - 9)/4;

    if(md == 2) return 1 + (n - 6)/4;

    return 2 + (n - 15)/4;
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

