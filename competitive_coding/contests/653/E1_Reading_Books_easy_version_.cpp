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
const ll inf = 1e18L + 5;


void solve(){
    ll n, k, t, a, b;
    cin>>n>>k;
    vector<ll> v[3];   /// 10, 01, 11
    rep(i, 1, n){
        cin>>t>>a>>b;
        if(a == 0 && b == 0) continue;
        if(a == 1 && b == 1) {
            v[2].push_back(t);
            continue;
        }
        v[b == 1].push_back(t);
    }

    fr(i, 3) sort(v[i].begin(), v[i].end());

    int m[3];
    fr(i, 3) m[i] = v[i].size();

    vector<ll> pref[3];
    fr(i, 3){
        ll sm = 0ll;
        for(auto it: v[i]){
            sm += it;
            pref[i].push_back(sm);
        }
    }

    /// linear search over the common list 
    ll res = inf;
    ll comm = 0ll;
    ll z;
    ll sm = 0ll;
    for(int i = 0; i <= min(k, (ll)m[2]); i++){
        z = k - i;  /// to be taken from other 2 lists
        sm = comm;

        if(z == 0){
            res = min(res, sm);
        }
        
        if(z && m[0] >= z && m[1] >= z){
            /// then only we can update
            fr(j, 2){
                sm += pref[j][z - 1];
            }
            res = min(res, sm);
        }

        if(i < m[2]){
            comm = pref[2][i];
        }
    }

    if(res == inf){
        cout<<-1<<endl;
    } else {
        cout<<res<<endl;
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

