/// below is correct solution. In my prev. attemot, I wasn't checking last a[i-1] and current a[i] elements if already marked in draw state.
/// so have to use map to mark them as such.

#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

unordered_map<ll, bool> mp;

ll findCount(ll x2, ll x1, ll y2, ll y1){
    /// x2>=x1 & y2>=y1
    if(x2 == x1 && y2 == y1)
        return 0;
    ll z1max = max(x1, y1);
    ll z2min= min(x2, y2);
    if(z1max > z2min){
        return 0;
    } else {
        if(mp[z1max] && mp[z2min]){
            return max(0ll, z2min - z1max -1);
        }
        if(mp[z1max] || mp[z2min]){
            mp[z1max] = true;
            mp[z2min] = true;
            return z2min - z1max;
        }

        else{
            mp[z1max] = true;
            mp[z2min] = true;
            return z2min - z1max + 1;
        }

    }
}

int main(){
    int n;
    cin>>n;
    ll a[n];
    ll b[n];
    ll count = 0;
    cin>>a[0];
    cin>>b[0];
    count += findCount(a[0], 0, b[0], 0);
    rep(i, 1, n-1){
        cin>>a[i];
        cin>>b[i];
        count += findCount(a[i], a[i-1], b[i], b[i-1]);
    }
    cout<<max(count, 1ll);
    return 0;
}
