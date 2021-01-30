/// if we set those indices which are not deleted yet as 1, then
/// question becomes "find first pos where prefix sum becomes delete query position"
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
int bit[N] = {0};   /// prefix sum, which are present

void update(int i, int upd){
    for(; i < N; i += i&(-i)) bit[i] += upd;
}

int get(int i){
    int sm = 0;
    for(; i > 0; i -= i&(-i)) sm += bit[i];
    return sm;
}

void solve(){
    int n, x, z;
    cin>>n;
    int a[n + 1];
    rep(i, 1, n) {
        cin>>a[i];
        update(i, 1);
    }

    rep(i, 1, n){
        cin>>x;

        int lb = 1, rb = n;
        while(lb < rb){
            int mb = (lb + rb)/2;
            if(get(mb) >= x){
                rb = mb;
            } else lb = mb + 1;
        }
        cout<<a[rb]<<" ";
        update(rb, -1);
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

