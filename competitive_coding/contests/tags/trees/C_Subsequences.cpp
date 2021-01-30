#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

const int N = 1e5 + 5;
ll bit[12][N], a[N];
int n, k;

void update(int idx, int i, ll val){
    for(; i<=n; i+=i&(-i)) bit[idx][i] += val;
}

ll pref(int idx, int i){
    ll sum = 0;
    for(; i>0; i -= i&(-i)) sum += bit[idx][i];
    return sum;
}

int main(){
    cin>>n>>k;
    rep(i, 1, n) cin>>a[i];
    rep(i, 1, n){
        update(1, a[i], 1);
        rep(j, 2, k+1){
            update(j, a[i], pref(j-1, a[i] - 1));
        }
    }
    ll ans = pref(k+1, n);
    cout<<ans;
}
