/// Min. Euler Cycle
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
    int n, l, r;
    cin>>n>>l>>r;

    vector<int> pref(n, 0);
    /// 1 2 1 3 1 4 | 2 3 2 4 | 3 4 | 1 => pref: 0, 6, 10, 12, 14
    /// pref[i]: starting at i + 1,
    pref[0] = 0;

    int sm = 0;
    rep(i, 1, n - 1){
        pref[i] = sm + (2 * (n - i));
        sm = pref[i];
    }

    int st = n;
    rep(i, 0, n - 1){
        if(pref[i] >= st){
            st = min(st, i);
        }
    }

    rep(i, st, n - 1){
        rep(j, i + 1, n - 1){

        }
    }

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

