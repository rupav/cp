#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
vector<ll> avengers;

ll thanosSnap(ll l, ll r, int a, int b, int n){
    ll i = lower_bound(avengers.begin(), avengers.end(), l) - avengers.begin();
    ll j = upper_bound(avengers.begin(), avengers.end(), r) - avengers.begin();
    ll avengers_count = j-i;
    ll minPower = 0;
    if(avengers_count == 0)
        return minPower = a;  /// destroy the whole base at once.
    else
        minPower = b*(avengers_count)*(r-l+1);
    if(l == r)
        /// can't split
        return minPower;
    ll mid = (l+r)/2;
    minPower = min(minPower, thanosSnap(l, mid, a, b, n)+thanosSnap(mid+1, r, a, b, n));
    return minPower;
}

int main(){
    int n, k, a, b;
    cin>>n>>k>>a>>b;
    ll val;
    fr(i, k){
        cin>>val;
        avengers.push_back(val);
    }
    ll base = (ll)1<<n;
    sort(avengers.begin(), avengers.end());
    cout<<thanosSnap(1, base, a, b, n);  /// 1-base indexed.
    return 0;
}

