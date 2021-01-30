#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


const int N = 2e5 + 5;


void solve(){
    int n;
    cin>>n;
    int v[n], d[n], p[n];
    fr(i, n) cin>>v[i]>>d[i]>>p[i];

    int tot(0);

    int conf; /// current confidence
    vector<int> el;
    bool gone[n] = {0}; /// child who has left

    int val;
    fr(i, n){
        if(gone[i]) continue;
        conf = p[i];
        el.push_back(i + 1);
        tot = 0;
        val = v[i];
        rep(j, i+1, n-1){
            if(gone[j]) continue;
            p[j] -= (val + tot);
            if(p[j] < 0){
                gone[j] = 1;
                tot += d[j];
            }
            val = max(val-1, 0ll);
        }
        gone[i] = 1;
    }

    cout<<el.size()<<endl;
    for(auto it: el) cout<<it<<" ";

}

signed main(){
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

