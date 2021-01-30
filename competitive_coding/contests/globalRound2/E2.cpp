#include<bits/stdc++.h>
#define mod 1000000007
#define lim 1000000000000000007
#define lim1 18446744073709551615  //Unsigned
#define sq(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<int,ll> pi;
typedef pair<pair<int,int>,int> pii;
ll power(ll a,ll b) {
    if (b==0) return 1;
    ll c = power(a,b>>1);
    c = (c*c)%mod;
    if (b&1) return (c*a)%mod;
    return c;
}
const int N = (int)3e5+5;
priority_queue<pi,vector<int>,greater<int> > pq;
multiset<pi> ms;
int a[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll ans = 0;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        if (a[i]>1) {
            ms.insert({i,a[i]});
            //pq.push(a[i]);
        }
    }
    for (int i=0;i<n;i++) {
        ans += ((ll)a[i])/3;
        if (a[i]>1)
            ms.erase(ms.find({i,a[i]}));
        a[i] %= 3;
        while (a[i]>0 && !ms.empty()) {
            auto it = ms.begin();
            ans++;
            a[i]--;
            pi temp = *it;
            a[temp.first] -= 2;
            ms.erase(it);
            if (a[temp.first]>1)
                ms.insert({temp.first,a[temp.first]});
        }
    }
    cout<<ans;
}


