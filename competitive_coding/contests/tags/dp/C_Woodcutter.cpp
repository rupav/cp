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
    vector<pii> v(n);
    fr(i, n) cin>>v[i].first>>v[i].second;

    int ans = min(n, 2);
    rep(i, 1, n-2){
        if(v[i].first - v[i].second > v[i-1].first){
            ans++;
        } else if (v[i].second + v[i].first < v[i+1].first){
            ans++;
            v[i].first = v[i].second + v[i].first;
        } else {
            // do nothing
        }
    }
    cout<<ans;

    return 0;
}
