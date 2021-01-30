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

ll binaryExponentiation(ll x, ll y){
    if(!y) return 1;
    if(y == 1) return x;
    if(y & 1ll){
        return (x*binaryExponentiation(x, y - 1ll));
    }
    ll c = binaryExponentiation(x, y/2ll);
    return c*c;
}

void solve(){
    ll k, z;
    cin>>k;
    vector<ll> v(11, 0);
    /// x^i.(x - 1)^(10 - i) >= k
    for(ll i = 1; i <= 10ll; i++){
        /// find x using binary search
        ll lb = 1, rb = 41;
        while(lb < rb){
            ll x = lb + (rb - lb)/2ll;
            z = binaryExponentiation(x, i) * binaryExponentiation(x - 1ll, 10ll - i);
            if(z >= k) rb = x;
            else lb = x + 1ll;
        }
        z = binaryExponentiation(rb, i) * binaryExponentiation(rb - 1ll, 10ll - i);
        if(z >= k){
            v[i] = rb;
        }
    }

    /// check for which sum of x is minimum
    ll mn = 500;
    ll tmp;
    ll pos = 1;
    for(ll i = 1; i <= 10; ++i){
        if(v[i]){
            ll x = v[i];
            tmp = i * x + (x - 1ll) * (10ll - i);
            if(tmp < mn){
                mn = tmp;
                pos = i;
            }
        }
    }

    ll x = v[pos];
    // cout<<mn<<" "<<pos<<" "<<x<<endl;
    string arr = "@codeforces";
    string s = "";
    rep(i, 1, pos) {
        fr(j, x) s += arr[i];
    }

    rep(i, pos + 1, 10){
        fr(j, x - 1) s += arr[i];
    }

    cout<<s;

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

