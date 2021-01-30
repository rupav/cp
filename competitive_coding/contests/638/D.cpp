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
const ll N = 1e9 + 5;

set<ll> s;
ll pw[30];

void solve(){
    ll n;
    cin>>n;

    /// edge case, n == 2
    if(n == 2){
        cout<<1<<endl<<0<<endl;
        return;
    }

    auto it = s.lower_bound(n);
    it = prev(it);
    ll val = *it;
    ll bits = __builtin_popcountll(val);
    ll d = bits - 1ll;

    ll diff = n - val;
    if(diff >= (val + 1ll)/2ll){
        cout<<d+1<<endl;
        fr(i, d) cout<<pw[i]<<" ";
        cout<<diff - pw[d]<<endl;
        return;
    } else {
        /// binary search over the answer, by backing up a set
        ll st(0), en(pw[d-1]);
        while(st <= en){
            ll m = (st + en)/2ll;
            ll val = pw[d+1] - 1ll + 2ll*m;
            ll k = n - val;
            if(k >= 0ll && k <= m + pw[d-1]){
                cout<<d+1<<endl;
                fr(i, d-1) cout<<pw[i]<<" ";
                cout<<m<<" "<<k<<endl;
                return;
            } else if (k < 0ll){
                en = m - 1;
            } else {
                /// k > m + pw[d-1]
                st = m + 1;
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    ll d = 0;
    pw[d++] = 1;
    ll val = 2ll;
    while(val <= N){
        s.insert(val - 1ll);
        pw[d++] = val;
        val *= 2ll;
    }

    while(t--){
        solve();
    }

    return 0;
}

