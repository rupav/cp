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
    ll n, k;
    cin>>n>>k;
    ll a[n];
    set<ll> s;
    ll uniq = 0;
    rep(i, 1, n) {
        cin>>a[i];
        s.insert(a[i]);
    }

    ll m = s.size();
    if(m > k) {
        cout<<-1<<endl;
        return;
    }

    vector<ll> ans(n*k, 1);
    int i = 0;
    for(auto it: s) ans[i++] = it;

    rep(i, k, n*k - 1){
        ans[i] = ans[i%k];
    }

    cout<<(n*k)<<endl;
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;
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

