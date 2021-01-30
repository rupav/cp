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
    int n, k;
    cin>>n>>k;
    int a[n];
    string s;
    cin>>s;
    int b[n];
    fr(i, n) a[i] = (int)(s[i] - '0');

    int mx[k] = {0};
    fr(i, n) {
        b[i] = a[i%k];
    }

    bool f = false;
    fr(i, n) {
        if(b[i] > a[i]) break;  /// now b is greater than a gauranteed
        if(b[i] < a[i]) {
            f = true;
            break;
        }
    }

    int ind = -1;
    if(f){
        repn(i, k-1, 0){
            if(a[i] < 9) {
                b[i] = a[i] + 1;
                ind = i - 1;
                break;
            } else b[i] = 0;
        }
        rep(i, 0, ind){
            b[i] = a[i];
        }
    }

    cout<<n<<endl;
    fr(i, n) cout<<b[i%k];
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

