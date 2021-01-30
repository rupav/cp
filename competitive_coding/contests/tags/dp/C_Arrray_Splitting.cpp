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
    int n, k;
    cin>>n>>k;
    int a[n];
    fr(i, n) cin>>a[i];
    vector<int> pq;
    rep(i, 1, n-1) pq.push_back(a[i-1] - a[i]);
    sort(pq.begin(), pq.end());
    cout<<accumulate(pq.begin(), pq.begin() + k-1, a[n-1] - a[0]);
    return 0;
}
