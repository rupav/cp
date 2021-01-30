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


void solve(){
    ll n;
    cin>>n;
    vector<ll> el;
    ll val = 1ll;
    ll sum = 1ll;
    while(sum <= n){
        el.push_back(val);
        val *= 2ll;
        sum += val;
    }

    sum -= val;

    if(sum < n){
        el.push_back(n - sum);
        sort(el.begin(), el.end());
    }

    int m = el.size();
    cout<<m-1<<endl;
    rep(i, 1, m-1) cout<<el[i] - el[i-1]<<" ";
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

