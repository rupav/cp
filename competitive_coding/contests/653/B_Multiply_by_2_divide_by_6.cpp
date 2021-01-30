#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    ll n;
    cin>>n;
    ll p[2] = {0ll};   /// 2 and 3
    while(n%2ll == 0){
        n /= 2ll;
        p[0]++;
    }
    while(n%3ll == 0){
        n /= 3ll;
        p[1]++;
    }
    if(n != 1 || p[1] < p[0]){
        cout<<-1<<endl;
    } else {
        cout<<p[1] - p[0] + p[1]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

