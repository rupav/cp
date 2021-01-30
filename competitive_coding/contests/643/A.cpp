#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    ll a, k, n;
    cin>>a>>k;
    ll mn, mx, mod;
    ll z;
    k--;
    while(k--){
        n = a;
        mn = 9;
        mx = 0;
        while(n){
            mod = n%10ll;
            mn = min(mn, mod);
            mx = max(mx, mod);
            n/=10ll;
        }
        z = mn*mx;
        if(!z) break;
        a += z;
    }

    cout<<a<<endl;
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
