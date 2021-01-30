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
#define int ll

int solve(){
    int n, x;
    cin>>n;
    map<int, int> mp;
    int mx = 0;
    fr(i, n){
        cin>>x;
        mp[x]++;
        mx = max(mx, mp[x]);
    }

    int cnt = 0;
    for(auto it: mp) {
        if(it.second == mx){
            cnt++;
        }
    }


    /// linear search over the answer
    int spaces = 0;
    // watch(cnt);
    int els = n - (mx * cnt);
    repn(i, n, 1){
        spaces = i - (cnt - 1);
        spaces *= (mx - 1);
        if(els >= spaces) return i;
    }

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

