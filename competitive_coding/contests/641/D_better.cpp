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
    int n, k;
    cin>>n>>k;
    int a[n];
    bool f = false;
    fr(i, n) {
        cin>>a[i];
        if(a[i] == k) f = true;
        a[i] = (a[i] >= k);
    }

    if(!f) return false;
    if(n == 1) return true;

    int sm = 0; /// sum of consecutive triplets
    fr(i, min(3, n)) sm += a[i];
    if(sm >= 2) return true;

    rep(i, 3, n-1){
        sm += a[i];
        sm -= a[i-3];
        if(sm >= 2) return true;
    }

    return false;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "yes" : "no")<<endl;
    }

    return 0;
}

