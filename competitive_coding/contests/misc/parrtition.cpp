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


void solve(){
    /// partition the array as per predicate, into 2 halves, useful for binary search to be applied over!
    /// T T T T ... T F F ... F
    /// partition returns iterator to first element of second group: 'partition_point'
    int n;
    cin>>n;
    vector<int> a(n);
    fr(i, n) cin>>a[i];

    auto IsOdd = [&](int x){
        return (x&1);
    };

   bool f = is_partitioned(a.begin(), a.end(), IsOdd);

   watch(f);

   auto z = partition(a.begin(), a.end(), IsOdd) - a.begin();
   watch(z);

   f = is_partitioned(a.begin(), a.end(), IsOdd);
   watch(f);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

