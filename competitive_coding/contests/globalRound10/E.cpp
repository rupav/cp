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
    ll n, q, k;
    cin>>n;

    ll a[n + 2][n + 2];
    a[1][1] = 0ll;
    for(int j = 1; j <= n; j += 2){
        rep(i, 1, n){
            if(i + 1 <= n) a[i + 1][j] = 0ll;
            if(j + 1 <= n){
                a[i][j + 1] = (1ll << (i + j - 2));
            }
        }
    }

    for(int j = 2; j <= n; j += 2){
        rep(i, 1, n){
            if(i + 1 <= n) a[i + 1][j] = (1ll << (i + j - 2));;
            if(j + 1 <= n){
                a[i][j + 1] = 0ll;
            }
        }
    }

    rep(i, 1, n){
        rep(j, 1, n){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cin>>q;
    int b = 2 * n - 2;

    while(q--){
        cin>>k;
        int col = 1, row = 1;
        cout<<"1 1"<<endl;
        fr(i, b){
            if(k & (1ll << i)){
                if(col&1){
                    cout<<row<<" "<<col + 1<<endl;
                    col++;
                } else {
                    cout<<row + 1<<" "<<col<<endl;
                    row++;
                }
            } else {
                if(col&1){
                    cout<<row + 1<<" "<<col<<endl;
                    row++;
                } else {
                    cout<<row<<" "<<col + 1<<endl;
                    col++;
                }
            }
        }
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

