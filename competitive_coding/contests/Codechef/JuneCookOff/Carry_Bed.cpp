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
#define int ll
ll mod = 1e9+7;

const int N = 5e3 + 5;
int a[N], L[N], R[N];
typedef long long ll;

void preprocess(int n){
    stack<int> s;
    for(int i=1; i<=n; i++) L[i] = 0;
    for(int i=1; i<=n; i++) R[i] = n+1;

    for(int i=1; i<=n; i++){
        while(s.size() && a[s.top()] < a[i]) s.pop();
        if(s.size()) L[i] = s.top();  // rightmost index, s.top() s.t. a[s.top()] <= a[i]
        s.push(i);
    }

    while(s.size()) s.pop();

    for(int i=n; i>=1; i--){
        while(s.size() && a[s.top()] <= a[i]) s.pop();
        if(s.size()) R[i] = s.top();  // leftmost index, s.top() s.t. a[s.top()] < a[i]
        s.push(i);
    }
}


void solve(){
    int n, k;
    cin>>n>>k;
    vector<pii> v(n), b(k);
    fr(i, n) {
        cin>>v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    fr(i, k) {
        b[i].first = v[i].second;
        b[i].second = v[i].first;
    }

    sort(b.begin(), b.end());
    fr(i, k) a[i + 1] = b[i].second;

    preprocess(k);
    ll mn = 1e18L + 5;
    ll c, fac;

    c = 0ll;
    rep(i, 1, k){
        // watch(a[i]);
        fac = min(i + 1, i - L[i]) * min(k - i + 1, R[i] - i);
        c += a[i] * fac;
    }
    mn = c;
    cout<<mn<<endl;
}

signed main(){
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

