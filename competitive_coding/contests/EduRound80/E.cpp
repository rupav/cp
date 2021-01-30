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

const int N = 6e5 + 5;
int bit[N];

void update(int i, int upd){
    for(; i < N; i += i&(-i)) bit[i] += upd;
}

int get(int i){
    int sm = 0;
    for(; i > 0; i -= i&(-i)) sm += bit[i];
    return sm;
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> mx(n+1), mn(n+1), pos(n+1);
    iota(mn.begin(), mn.end(), 0);
    iota(pos.begin(), pos.end(), 1);
    iota(mx.begin(), mx.end(), 0);
    reverse(pos.begin(), pos.end());

    rep(i, 1, n) update(i, 1);

    int x, z;
    rep(i, 1, m){
        cin>>x;
        mn[x] = 1;
        z = get(n + m) -  get(pos[x]);  /// right of current element count
        mx[x] = max(mx[x], z + 1);
        update(pos[x], -1);
        pos[x] = n + i; /// top of the list
        update(pos[x], 1);
    }


    rep(x, 1, n){
        z = get(n + m) - get(pos[x]);
        mx[x] = max(mx[x], z + 1);
    }

    rep(i, 1, n) cout<<mn[i]<<" "<<mx[i]<<endl;
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
