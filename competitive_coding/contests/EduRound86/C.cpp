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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

const ll N = 1e18 + 5;

void solve(){
    ll a, b, q, l, r;
    cin>>a>>b>>q;
    ll lcm = (a*b)/gcdll(a, b);

    if(a < b){
        ll t = b;
        b = a;
        a = t;
    }

    ll st, en;
    ll eq = 0ll;

    ll z = 0;
    fr(i, q){
        cin>>l>>r;
        eq = 0ll;
        st = (l + lcm + 1ll)/lcm;
        en = (r)/lcm;

        eq += max(z, (en - st))*a;  /// complete!

        st = (l/lcm)*lcm;
        for(ll i = st; i < st + a; i++){
            if(i >= l && i <= r) eq++;
        }

        en *= lcm;
        if(en != st){
            for(ll i = en; i < en + a; i++){
                if(i <= r && i >= l) eq++;
            }
        }


        cout<<(r - l + 1ll - eq)<<endl;
    }

    cout<<endl;
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

