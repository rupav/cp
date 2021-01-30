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

const int N = 2e5+5;

int main(){
    int n, k;
    cin>>n>>k;
    ll arr[n+1];
    rep(i, 1, n) cin>>arr[i];

    ll a, b;
    ll sum = -1;

    /// check for each possible a from right to left, at each stage, only 1 b is compared with previous b's
    ll pref[n+1] = {0};
    rep(i, 1, n) pref[i] = pref[i-1] + arr[i];

    ll max_b = -1;
    ll max_  = -1;
    ll sum_a, sum_b;
    ll b_;

    for(int i=n-2*k+1; i>0; i--){
        sum_a = pref[i+k-1] - pref[i-1];
        sum_b = pref[i+2*k-1] - pref[i+k-1];
        max_b = max(sum_b, max_b);

        if(max_b == sum_b) b_ = i+k;
        if(sum_a + max_b >= max_){
            max_ = sum_a + max_b;
            a = i;
            b = b_;
        }
    }

    cout<<a<<" "<<b;

}
