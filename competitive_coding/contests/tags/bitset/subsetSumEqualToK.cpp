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

const int MAX_W = 1e5 + 5;
bitset<MAX_W> can;    /// whether sum is possible or not

void solve(){
    int n, w, x;
    cin>>n>>w;  /// find if subset with sum w exists
    can[0] = true;  /// sum = 0 is always possible!
    fr(i, n){
        cin>>x;
        can |= (can << x);
    }
    cout<<(can[w] ? "Yes": "No")<<endl;
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

