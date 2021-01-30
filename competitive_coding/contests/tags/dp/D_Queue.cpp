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
    ll a[n];
    fr(i, n) cin>>a[i];
    sort(a, a+n);
    ll sum = a[0];
    int ans = 0;
    rep(i, 1, n-1){
        if(sum > a[i]){
            ans++;
            /// if this person is disappointed, send him to end of the queue! i.e. dont count his serving time
            sum -= a[i];
        }
        sum += a[i];
    }
    cout<<n-ans;
    return 0;
}
