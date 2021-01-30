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
    int n;
    cin>>n;
    int a[n];
    fr(i, n) cin>>a[i];
    int ans = 0;

    fr(x, 31){
        int mx = 0;
        int sm = 0;
        fr(i, n){
            if(a[i] > x) {
                sm = 0;
                continue;
            }
            sm = max(a[i] + sm, a[i]);
            mx = max(mx, sm);
        }
        ans = max(ans, mx - x);
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

