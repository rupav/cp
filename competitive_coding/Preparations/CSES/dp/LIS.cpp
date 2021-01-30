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

vector<int> a;
int LIS(int n){
    vector<int> lis;
    lis.push_back(0);   /// dummy
    for(auto it: a){
        auto ub = lower_bound(lis.begin(), lis.end(), it) - lis.begin();
        if(ub == lis.size()) lis.push_back(it);
        else lis[ub] = it;
    }
    return (int) lis.size() - 1;
}

void solve(){
    int n;
    cin>>n;
    a.resize(n);
    fr(i, n) cin>>a[i];
    cout<<LIS(n);
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

