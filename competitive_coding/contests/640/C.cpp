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


ll solve(){
    ll n, k;
    cin>>n>>k;
    ll l(1), r(n*k + 1ll);
    while(l <= r){
        ll m = (l + r)/2ll;
        ll cnt = m - m/n;
        if(cnt == k) {
            if(m%n == 0) return m-1;
            return m;
        }
        if(cnt > k){
            r = m - 1ll;
        } else {
            l = m + 1ll;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

