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

const int N = 2e5 + 5;
int t[2 * N];

int init(){
    return 0;
}

int combine(int a, int b){
    return a ^ b;
}

void build(int n){
    for(int i = n - 1; i >= 1; i--) t[i] = combine(t[(i<<1)], t[(i<<1)|1]);
}

/// [l, r)
int get_xor(int n, int l, int r){
    int res = init();
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) res = combine(res, t[l++]);
        if(r & 1) res = combine(res, t[--r]);
    }
    return res;
}

void solve(){
    int n, q, x, l, r;
    cin>>n>>q;
    fr(i, n) cin>>t[n + i];
    build(n);
    fr(i, q){
        cin>>l>>r;
        l--, r--;
        cout<<get_xor(n, l, r+1)<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll tc = 1;
    //  cin>>t;
    while(tc--){
        solve();
    }

    return 0;
}



