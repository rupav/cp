#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


int solve(){
    int n;
    cin>>n;
    int a[n+2];
    rep(i, 1, n) cin>>a[i];
    int l[n+2], r[n+2];
    l[0] = r[0] = l[n+1] = r[n+1] = 0;
    a[0] = numeric_limits<ll>::max();
    a[n+1] = 0;
    rep(i, 1, n){
        l[i] = 1;
        if(a[i] > a[i-1]) l[i] += l[i-1];
    }

    repn(i, n, 1){
        r[i] = 1;
        if(a[i] < a[i+1]) r[i] += r[i+1];
    }

    int mx = 1;

    rep(i, 1, n){
        /// changing this element
        mx = max({mx, l[i], r[i], l[i-1] + 1, r[i+1] + 1});
        if(a[i-1] < a[i+1] - 1) mx = max(mx, l[i-1] + r[i+1] + 1);
    }

    return mx;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

