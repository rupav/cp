/// similar to knapsack 0/1 problem
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

void max_self(int &a, int b){
    a = max(a, b);
}

void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> p(n), s(n);
    fr(i, n) cin>>p[i];
    fr(i, n) cin>>s[i];

    vector<int> knapsack(x + 1, 0); /// dp[i] = max. value/pages we can get within total capacity/price i

    for(int book = 0; book < n; book++){
        for(int price_already = x - p[book]; price_already >= 0; --price_already){
            max_self(knapsack[price_already + p[book]], knapsack[price_already] + s[book]);
        }
    }

    cout<<knapsack[x];
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

