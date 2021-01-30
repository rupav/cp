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
    int n;
    cin>>n;
    int a[n+1];
    rep(i, 1, n) cin>>a[i];
    vector<int> b;

    rep(i, 1, n){
        if(i == 1 || i == n || (a[i - 1] < a[i]) != (a[i] < a[i + 1]))
            b.push_back(a[i]);
    }

    cout<<b.size()<<endl;
    for(auto it: b) cout<<it<<" ";
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

