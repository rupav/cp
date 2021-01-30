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


void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    fr(i, n) cin>>a[i];
    int lb(0), rb(m);
    int ans = rb;

    while(lb <= rb){
        int mb = (lb + rb)/2;
        /// check for mb operations, if non-decreasing sequence is possible
        /// total operations required is max of operation required on a single experiment!
        int prev = 0;
        bool f = true;
        fr(i, n){
            if(a[i] == prev) continue;
            if(a[i] < prev){
                if(prev - a[i] > mb) {
                    f = false;
                    break;
                } else {
                    continue;
                }
            } else {
                if(m - a[i] + prev > mb) prev = a[i];
                else continue;
            }
        }
        if(f){
            ans = min(ans, mb);
            rb = mb - 1;
        } else lb = mb + 1;
    }

    cout<<ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

