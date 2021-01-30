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


bool solve(){
    int a[2], b[2];
    fr(i, 2) cin>>a[i]>>b[i];

    if(a[0] == a[1] && b[1] + b[0] == a[0]) return true;
    if(a[0] == b[1] && a[1] + b[0] == a[0]) return true;
    if(b[0] == a[1] && b[1] + a[0] == b[0]) return true;
    if(b[0] == b[1] && a[1] + a[0] == b[0]) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "YES" : "NO")<<endl;
    }

    return 0;
}

