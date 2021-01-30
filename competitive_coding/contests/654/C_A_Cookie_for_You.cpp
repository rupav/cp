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


bool solve(){
    ll a, b, n, m;
    cin>>a>>b>>n>>m;
    ll z = 0ll;

    if(a > b){
        if(m > b) return false;
        b -= m;
        return n <= a + b;
    } else {
        /// a <= b
        if(m > a) return false;
        a -= m;
        return n <= a + b;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "Yes": "No")<<endl;
    }

    return 0;
}

