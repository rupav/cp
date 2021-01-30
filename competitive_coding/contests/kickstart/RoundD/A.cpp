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
    int a[n + 1];
    fr(i, n) cin>>a[i];
    a[n] = -1;
    int mx = -1;
    int cnt = 0;
    fr(i, n){
        if(a[i] > mx && a[i] > a[i + 1]) cnt++;
        mx = max(mx, a[i]);
    }
    cout<<cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    rep(tc, 1, t){
        cout<<"Case #"<<tc<<": ";
        solve();
        cout<<endl;
    }

    return 0;
}

