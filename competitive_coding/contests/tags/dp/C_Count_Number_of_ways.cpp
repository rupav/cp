#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    fr(i, n) cin>>a[i];

    ll sum = accumulate(a, a+n, 0ll);
    if(sum%3 != 0){
        cout<<0;
        return 0;
    }

    ll x = sum/3;
    bool p[n] = {false};
    sum = 0ll;
    for(int i=n-1; i>=0; i--){
        sum += a[i];
        if(sum == x) p[i] = true;
    }

    ll p_sum[n];
    sum = 0ll;

    for(int i=n-1; i>=0; i--){
        p_sum[i] = sum + p[i];
        sum = p_sum[i];
    }

    sum = 0ll;
    ll ans = 0ll;
    fr(i, n-2){
        sum += a[i];
        if(sum == x){
            ans += p_sum[i+2];
        }
    }

    cout<<ans;

    return 0;
}
