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


void solve(){
    string s;
    cin>>s;
    ll n = s.size();
    ll mp[n + 2] = {0};
    ll sm = 0;
    fr(i, n){
        sm += (s[i] == '-');
        sm -= (s[i] == '+');
        if(sm > 0ll && !mp[sm]) mp[sm] = i + 1ll;
    }

    /// similate untin n + 1 iterations max
    ll res = 0ll;

    ll x;
    rep(i, 0, n){
        /// check first pos of sum i + 1
        x = mp[i + 1];
        if(x){
            res += x;
        } else {
            /// ok is true, take the whole
            res += n;
            break;
        }
    }

    cout<<res<<endl;

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

