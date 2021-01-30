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
    int n;
    cin>>n;
    int a[n], b[n];
    bool f[2] = {0};
    fr(i, n) cin>>a[i];
    fr(i, n) {
        cin>>b[i];
        f[b[i]] = 1;
    }

    if(f[0] & f[1]){
        return true;
    } else {
        /// must be sorted!
        rep(i, 1, n - 1){
            if(a[i] < a[i - 1]) return false;
        }
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
        cout<<(solve() ? "YES": "NO")<<endl;
    }

    return 0;
}

