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


void solve(){
    int n, x;
    cin>>n;
    int a[n];
    int tot = 0;
    fr(i, n){
        cin>>x;
        if(x == 1){
            tot++;
            a[i] = -1;
        } else {
            a[i] = 1;
        }
    }

    /// find max sum segment in the array
    int best = -INT_MAX;
    int sm = 0;
    fr(i, n){
        sm += a[i];
        best = max(best, sm);
        sm = max(sm, 0);
    }


    cout<<tot + best;
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

