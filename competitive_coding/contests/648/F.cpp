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


bool solve(){
    int n;
    cin>>n;
    int a[n], b[n];
    map<pii, int> mp;
    fr(i, n) cin>>a[i];
    fr(i, n) cin>>b[i];

    if(n & 1){
        if(a[n/2] != b[n/2]) return false;
    }

    fr(i, n/2){
        int mn = min(a[i], a[n - i - 1]);
        int mx = max(a[i], a[n - i - 1]);
        mp[make_pair(mn, mx)]++;
    }

    fr(i, n/2){
        int mn = min(b[i], b[n - i - 1]);
        int mx = max(b[i], b[n - i - 1]);
        if(!mp[{mn, mx}]) return false;
        mp[{mn, mx}]--;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "YES": "NO")<<endl;
    }

    return 0;
}

