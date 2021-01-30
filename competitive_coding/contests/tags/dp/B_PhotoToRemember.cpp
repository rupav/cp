#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<pii> a(n);
    multiset<int> ms;
    int sum = 0;
    fr(i, n){
        cin>>a[i].first>>a[i].second;
        sum += a[i].first;
        ms.insert(a[i].second);
    }

    for(auto it: a){
        sum -= it.first;
        ms.erase(ms.lower_bound(it.second));
        int max_ = *ms.rbegin();
        cout<<max_*sum<<" ";
        ms.insert(it.second);
        sum += it.first;
    }

    return 0;
}
