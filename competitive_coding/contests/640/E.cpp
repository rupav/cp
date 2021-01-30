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
    int a[n+1];
    int cnt[n+1] = {0};
    int z = 0;
    rep(i, 1, n) {
        cin>>a[i];
        cnt[a[i]]++;
    }

    int pref[n+1] = {0};
    rep(i, 1, n) pref[i] = pref[i-1] + a[i];

    int d;
    rep(i, 1, n){
        rep(j, i+1, n){
            d = pref[j] - pref[i-1];
            if(d > n) break;
            if(d <= n && cnt[d]) {
                z += cnt[d];
                cnt[d] = 0;
            }
        }
    }

    cout<<z<<endl;
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

