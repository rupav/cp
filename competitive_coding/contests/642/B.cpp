#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


ll solve(){
    ll n, k;
    cin>>n>>k;
    ll a[n], b[n];
    fr(i, n) cin>>a[i];
    fr(i, n) cin>>b[i];
    sort(a, a+n);
    sort(b, b+n, greater<ll>());

    fr(i, k){
        if(a[i] < b[i]){
            a[i] = b[i];
        } else break;
    }

    ll sum = accumulate(a, a+n, 0ll);
    return sum;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

