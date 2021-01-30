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

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool check(int nx, int ny, int n, int m){
    if(nx < 1 || nx > n) return false;
    if(ny < 1 || ny > m) return false;
    return true;
}

void solve(){
    int n, m;
    cin>>n>>m;
    int a[n + 1][m + 1];
    rep(i, 1, n){
        rep(j, 1, m) cin>>a[i][j];
    }
    int b[n + 1][m + 1];

    bool f = true;
    rep(i, 1, n){
        rep(j, 1, m){
            int cnt = 0;
            fr(k, 4){
                int nx = i + dx[k];
                int ny = j + dy[k];
                cnt += check(nx, ny, n, m);
            }
            b[i][j] = cnt;
            f = f & (b[i][j] >= a[i][j]);
        }
    }

    if(!f){
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        rep(i, 1, n){
            rep(j, 1, m){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

