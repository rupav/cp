#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

const int INF = INT_MAX;
const int nax = 1e3 + 5;

void solve_(){
    /// greedy
    int n, m, x, y;
    cin>>n>>m>>x>>y;

    ll cost = 0ll;
    string s;
    int st, en, j, k, len;
    fr(i, n){
        cin>>s;
        j = 0;
        while(j < m){
            if(s[j] == '.'){
                k = j + 1;
                while(k < m && s[k] == '.') k++;
                len = k - j;
                if(len & 1) {
                    cost += x;
                    len--;
                }

                if(y < 2*x) cost += (len/2)*y;
                else cost += len*x;

                j = k;
            } else j++;
        }
    }

    cout<<cost<<endl;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve_();
    }

    return 0;
}

