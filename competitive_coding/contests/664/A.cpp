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
    ll a[4];
    bool f[4];
    int odd = 0;
    fr(i, 4) {
        cin>>a[i];
        f[i] = a[i]&1ll;
        odd += f[i];
    }
    if(odd <= 1) return true;
    /// increment if poss
    odd = 0;
    if(a[0] && a[1] && a[2]){
        fr(i, 3) {
            f[i] = !f[i];
            odd += f[i];
        }
        a[3]++;
        f[3] = a[3]&1ll;
        odd += f[3];
        if(odd <= 1) return true;
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
        cout<<(solve() ? "YES": "NO")<<endl;
    }

    return 0;
}
