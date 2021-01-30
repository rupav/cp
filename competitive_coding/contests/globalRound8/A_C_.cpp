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
    ll a, b, n;
    cin>>a>>b>>n;
    vector<ll> res;
    ll sm = 0ll;
    ll mx = max(a, b);
    ll mn = min(a, b);
    b = mx;
    a = mn;

    ll k = 0ll;
    ll t, t1 = a, t2 = b;
    while(t2 <= n){
        t = t2 + t1;
        t1 = t2;
        t2 = t;
        k++;  
    }

    res.push_back(k);

    b = mn;
    a = mx;

    k = 0ll;
    t, t1 = a, t2 = b;
    while(t2 <= n){
        t = t2 + t1;
        t1 = t2;
        t2 = t;
        k++;  
    }
    res.push_back(k);

    k = (n - mn)/mx + 1ll;
    res.push_back(k);

    cout<<*min_element(res.begin(), res.end())<<endl;

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

