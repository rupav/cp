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

/// primitive functions
ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

bool solve(){
    ll n;
    cin>>n;
    ll a[n], b[n];
    fr(i, n) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    ll mn = *min_element(a, a + n);
    vector<bool> f(n, false);
    fr(i, n){
        if(gcdll(mn, a[i]) != mn) f[i] = true;
    }

    fr(i, n){
        if(f[i] && (b[i] != a[i])) return false;
    }
    return true;

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

