#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

const int N = 5e5+5;
ll a[N], L[N], R[N];

void fill_(int n){
    stack<int> s;
    for(int i=1; i<=n; i++) L[i] = 0;
    for(int i=1; i<=n; i++) R[i] = n+1;

    for(int i=1; i<=n; i++){
        while(s.size() && a[s.top()] >= a[i]) s.pop();
        if(s.size()) L[i] = s.top();  // rightmost index, s.top() s.t. a[s.top()] <= a[i]
        s.push(i);
    }

    while(s.size()) s.pop();

    for(int i=n; i>=1; i--){
        while(s.size() && a[s.top()] >= a[i]) s.pop();
        if(s.size()) R[i] = s.top();  // leftmost index, s.top() s.t. a[s.top()] < a[i]
        s.push(i);
    }
}

void solve(){
    ll n;
    cin>>n;
    rep(i, 1ll, n) cin>>a[i];

    fill_(n);

    ll l[n+2], r[n+2];
    l[0] = 0ll;
    r[n+1] = 0ll;

    rep(i, 1ll, n){
        l[i] = l[L[i]] + (i - L[i])*a[i];
    }

    for(ll i=n; i>=1ll; i--){
        r[i] = r[R[i]] + (R[i] - i)*a[i];
    }

    ll ind = 1ll;
    ll max_ = l[1] + r[1] - a[1];

    rep(i, 1, n){
        if(l[i] + r[i] - a[i] > max_){
            max_ = l[i] + r[i] - a[i];
            ind = i;
        }
    }

    ll ans[n+1];

    max_ = a[ind];
    rep(i, ind, n){
        max_ = min(max_, a[i]);
        ans[i] = max_;
    }

    max_ = a[ind];
    for(ll i=ind; i>=1; i--){
        max_ = min(max_, a[i]);
        ans[i] = max_;
    }

    rep(i, 1ll, n) cout<<ans[i]<<" ";

}

signed main(){
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

