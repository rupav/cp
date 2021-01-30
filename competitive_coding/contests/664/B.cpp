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
    int n, m, a, b, x, y;
    cin>>n>>m>>a>>b;
    /// from each cell, complete all its column cell!
    rep(i, a, n){
        cout<<i<<" "<<b<<endl;
    }
    repn(i, a - 1, 1){
        cout<<i<<" "<<b<<endl;
    }

    // definitely at 1, b right now
    bool f = true;
    int col = 1;
    while(col <= m){
        if(col == b){
            col++;
            continue;
        }
        if(f){
            rep(i, 1, n){
                cout<<i<<" "<<col<<endl;
            }
        } else {
            repn(i, n, 1){
                cout<<i<<" "<<col<<endl;
            }
        }
        f = !f;
        col++;
    }

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

