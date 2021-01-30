/// count of matchings
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
int mod = 1e9+7;

const int nax = 21;
int ALL_ONE = (1<<nax) - 1;

void add_self(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}

int dp[(1<<nax)][nax];
int n;
int a[nax][nax];

int recurse(int mask, int id){
    if(mask == ALL_ONE) return 1;
    if(id == n) return 0;

    int &z = dp[mask][id];
    if(~z) return z;

    z = 0;
    int temp = 0;
    for(int i=0; i<n; i++){
        if(a[i][id] && !(mask&(1<<i))){
            add_self(z, recurse(mask|(1<<i), id+1));
        }
    }
    return z;
}

void solve(){
    cin>>n;
    fr(i, n) fr(j, n) cin>>a[i][j];
    ALL_ONE = (1<<n) - 1;

    rep(i, 0, ALL_ONE){
        rep(j, 0, n-1) dp[i][j] = -1;
    }

    cout<<recurse(0, 0)<<endl;
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

