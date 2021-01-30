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
    ll x, y;
    int n;
    string s;
    cin>>x>>y;
    cin>>s;
    n = s.size();

    ll md;  /// manhatten distance

    fr(i, n){
        if(s[i] == 'E') x++;
        else if(s[i] == 'W') x--;
        else if(s[i] == 'S') y--;
        else y++;
        md = llabs(x) + llabs(y);
        // watch(md);
        if(i + 1 >= md) {
            cout<<i+1;
            return;
        }
    }

    cout<<"IMPOSSIBLE";
    return;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    rep(i, 1, t){
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<endl;
    }

    return 0;
}

