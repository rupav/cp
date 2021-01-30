#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pii;
ll mod = 1e9+7;

priority_queue<pii> pq;  /// Max Heap
set<pii> s;  /// associative sorted container!

int main(){
    int n, k;
    cin>>n>>k;
    ll t, b, sum = 0;
    rep(i, 1, n){
        cin>>t>>b;
        pq.push(mp(b, t));
    }

    int i = 1;
    ll ans = 0;
    while(!pq.empty()){
        pii temp = pq.top();
        pq.pop();
        sum += temp.second;
        s.insert(mp(temp.second, i++));
        if(s.size() > k){
            /// we need to remove min. t element, but what if its the just inserted elemented - that would still not affect the ans, since current beauty is gauranteed less than previous batch' beauty, and in both cases, sum will be same.
            auto it = s.begin();
            sum -= it->first;
            s.erase(it);
        }
        ans = max(ans, sum*temp.first);
    }

    cout<<ans;

    return 0;
}

