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


ll solve(){
    ll a, b;
    cin>>a>>b;
    if(a > b){
        ll tmp = b;
        b = a;
        a = tmp;
    }

    /// now 2, 4, 8 mul only possible

    ll cnt = 0;

    while(a <= b){
        a *= 2ll;
        cnt++;
    }

    /// a > b;
    cnt--;
    a /= 2ll;
    if(a != b) return -1;

    ll ops = cnt/3ll;
    cnt = cnt % 3ll;
    ops += cnt/2ll;
    cnt = cnt % 2ll;
    ops += cnt;

    return ops;

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

