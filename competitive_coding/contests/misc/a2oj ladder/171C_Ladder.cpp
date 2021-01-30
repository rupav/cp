#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

int n;
const int N = 1e5 + 5;
int a[N], L[N], R[N];

void preprocess(int n){
    for(int i=0; i<=n+1; i++) L[i] = 0;
    for(int i=0; i<=n+1; i++) R[i] = n+1;

    for(int i=1; i<=n; i++){
        if(a[i] >= a[i-1]) L[i] = L[i-1];
        else L[i] = i - 1;
    }

    for(int i=n; i>0; i--){
        if(a[i] >= a[i+1]) R[i] = R[i+1];
        else R[i] = i + 1;
    }
}

pll t[2 *N];    /// for holding max, and index of the element as well

void build(){
    for(int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

pll query(int l, int r){
    pll res = {-1ll, -1ll};
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1ll) res = max(res, t[l++]);
        if(r&1ll) res = max(res, t[--r]);
    }
    return res;
}

void solve(){
    int q, l, r;
    cin>>n>>q;
    rep(i, 1, n) cin>>a[i];

    preprocess(n);
    fr(i, 2*N) t[i] = {-1, -1};
    rep(i, 1, n){
        // t[n + i - 1] = {i - L[i] + R[i] - i - 1ll, i}; // either make segTree using max coverage or its original value
        t[n + i - 1] = {a[i], i};
    }
    build();

    int index;
    bool f;
    while(q--){
        cin>>l>>r;
        l--, r--;   /// 0-based seg tree
        index = query(l, r + 1).second;
        l++, r++;
        f = true;
        if(L[index] >= l || R[index] <= r) f = false;

        cout<<(f ? "Yes" : "No")<<endl;
    }

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

