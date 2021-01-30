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

int bound_lower(const vector<int> &a, int x){
    /// returns index of first val which is >= x
    int n = a.size();
    int lb(0), rb(n - 1);
    while(lb < rb){
        int mb = lb + (rb - lb)/2;
        if(a[mb] >= x) rb = mb;
        else lb = mb + 1;
    }
    return (a[rb] >= x ? rb : n);
}

int bound_upper(const vector<int> &a, int x){
    /// returns index of first val which is > x
    int n = a.size();
    int lb(0), rb(n - 1);
    while(lb < rb){
        int mb = lb + (rb - lb)/2;
        if(a[mb] > x) rb = mb;
        else lb = mb + 1;
    }
    return (a[rb] > x ? rb : n);
}

int lst_bound_lower(const vector<int> &a, int x){
    /// returns last index for which val is not is greater than x i.e index just before upper_bound
    int n = a.size();
    int lb(0), rb(n - 1);
    while(lb < rb){
        int mb = lb + (rb - lb + 1)/2;
        if(a[mb] <= x) lb = mb;
        else rb = mb - 1;
    }
    return (a[rb] <= x ? rb : n);
}


void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    // iota(a.begin(), a.end(), 0);
    fr(i, n) cin>>a[i];

    auto z = lst_bound_lower(a, x);
    auto lb = lower_bound(a.begin(), a.end(), x) - a.begin();
    watch(z);
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

