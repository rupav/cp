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
    int n;
    cin>>n;
    map<int, int> mp;
    int fac = 1;
    int cnt = 0;
    while(n){
        int z = n%10;
        mp[z*fac]++;
        n /= 10;
        fac *= 10;
        cnt++;
    }

    int sz = cnt - mp[0];
    cout<<sz<<endl;
    mp.erase(mp.find(0));
    for(auto it: mp){
        rep(i, 1, it.second){
            cout<<it.first<<" ";
        }
    }
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

