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
    int n;
    cin>>n;
    set<int> s;
    rep(i, 0, 2e5 + 5) s.insert(i);
    int a[n + 1];
    bool f = true;
    rep(i, 1, n){
        cin>>a[i];
        if(a[i] > i) f = false;
        s.erase(a[i]);
    }

    if(!f){
        cout<<"-1";
        return;
    }

    /// put whatever not in set!
    int b[n + 1];

    int mx;
    rep(i, 1, n){
        /// a[i] < i
        mx = *s.begin();
        b[i] = mx;
        s.erase(mx);
        if(i + 1 <= n && a[i] != a[i + 1]){
            /// we can now use this a[i]
            s.insert(a[i]);
        }
    }

    rep(i, 1, n) cout<<b[i]<<" ";
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

