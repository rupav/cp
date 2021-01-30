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
    int n;
    ll x, k;
    cin>>n>>k;
    int a[n + 1];
    bool exists = false;
    rep(i, 1, n){
        cin>>x;
        if(x == k) {
            a[i] = 0;
            exists = true;
        }
        if(x > k) a[i] = 1;
        if(x < k) a[i] = -1;
    }

    if(!exists) return false;

    /// edge case
    bool f = true;
    rep(i, 1, n) if(a[i]) f = false;
    if(f) return f;


    rep(i, 3, n){
        x = a[i];
        if(x >= 0 && a[i-2] >= 0) return true;
    }

    rep(i, 2, n){
        x = a[i];
        if(x >= 0 && a[i-1] >= 0) return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        cout<<(solve() ? "yes" : "no")<<endl;
    }

    return 0;
}

