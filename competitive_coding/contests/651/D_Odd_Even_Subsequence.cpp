#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    int n, k;
    cin>>n>>k;
    int a[n];
    int b[n];
    int mn = INT_MAX, mx = 0;
    fr(i, n) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    /// binary search over the answer
    int lb = 0, rb = n - 1;

    while(lb < rb){
        int x = lb + (rb - lb)/2ll;
        /// check if possible to have answer <=x
        int i, sz;
        if(k&1ll){
            i = 0;
            sz = 0;
            while(i < n) {
                if(a[i] <= b[x]) {
                    sz++;
                    i += 2ll; /// we can't take i + 1 anyways now
                } else i++;
            }
        } else {
            /// we can't take last
            i = 0;
            sz = 0;
            while(i < n - 1ll) {
                if(a[i] <= b[x]) {
                    sz++;
                    i += 2ll; /// we can't take i + 1 anyways now
                } else i++;
            }
        }

        bool f = false;
        /// check if ceil(k/2) is possible subsequence of odd parity
        int z = (k + 1ll)/2ll;
        if(sz >= z) f = true;

        z = k/2ll;    /// even parity sequence, 
        
        if(k&1ll){
            // for this a[0] & a[n - 1] cant be taken!
            i = 1;
            sz = 0;
            while(i < n - 1ll){
                if(a[i] <= b[x]){
                    sz++;
                    i += 2ll;
                } else i++;
            }
        } else {
            /// we just cant include 1st element, last can be included
            i = 1;
            sz = 0;
            while(i < n){
                if(a[i] <= b[x]){
                    sz++;
                    i += 2ll;
                } else i++;
            }            
        }

        if(sz >= z) f = true;

        if(f){
            rb = x;
        } else lb = x + 1;

    }
    /// ans is min value less than rb!
    cout<<b[rb];
}

signed main(){
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

