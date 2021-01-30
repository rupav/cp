/// https://www.codechef.com/LTIME85A/problems/MAXAND18
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

const int sz = 30;

void solve(){
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    vector<pll> c(sz, make_pair(0ll, 0ll));
    fr(i, n) {
        cin>>a[i];
        fr(j, sz){
            if(a[i] & (1ll << j))
                c[j].first += (1ll << j);
            c[j].second = j;
        }
    }

    auto comp = [&](pll a, pll b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    };

    sort(c.begin(), c.end(), comp);
    ll x = 0ll;
    ll sm = 0ll;
    fr(i, k){
        // cout<<c[i].first<<endl;
        int j = c[i].second;
        sm += c[i].first;
        x += (1ll << j);
    }
    // watch(sm);
    cout<<x<<endl;
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

