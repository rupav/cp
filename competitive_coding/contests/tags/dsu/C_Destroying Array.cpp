#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll a[n+1];
    ll pref[n+1] = {0};
    for(int i=1; i<=n; i++) cin>>a[i], pref[i] = pref[i-1] + a[i];

    priority_queue<ll> pq;
    int di;
    set<int> s;
    multiset<ll> sum; // sum of segments
    sum.insert(pref[n]);

    ll temp = 0ll;
    s.insert(0);    // deleted elements set
    s.insert(n+1);
    int prev[n+1];

    for(int i=1; i<=n; i++){
        cin>>di;  // 1 to n
        auto ub = s.upper_bound(di);
        auto lb = std::prev(ub);
        temp = pref[*ub - 1] - pref[*lb];
        sum.erase(sum.find(temp));
        temp = pref[di - 1] - pref[*lb];
        sum.insert(temp);
        temp = pref[*ub - 1] - pref[di];
        sum.insert(temp);
        s.insert(di);

        cout<<(*sum.rbegin())<<endl;
    }

    return 0;
}
