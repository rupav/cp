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


void solve(){
    ll n[3];
    fr(i, 3) cin>>n[i];
    vector<vector<ll>> a(3);
    ll x;
    fr(i, 3){
        fr(j, n[i]){
            cin>>x;
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end(), greater<ll>());
    }

    ll dp[n[0] + 1][n[1] + 1][n[2] + 1];
    fr(i, n[0]){
        fr(j, n[1]){
            fr(k, n[2]) dp[i][j][k] = 0;
        }
    }

    ll ans = 0ll;

    fr(i, n[0]){
        fr(j, n[1]){
            fr(k, n[2]){

            }
        }
    }


    cout<<ans;
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

