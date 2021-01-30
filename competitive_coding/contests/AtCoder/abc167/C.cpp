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

const int inf = INT_MAX;
int n, m, x;
vector<int> c;
vector<vector<int>> a;
int ans = inf;

void rec(int i, int mask, vector<int>& v, int cost){
    int mn = *min_element(v.begin(), v.end());
    if(mn >= x){
        ans = min(ans, cost);
        return;
    }
    if(i == n) return;

    rec(i+1, mask, v, cost);

    fr(j, m) v[j] += a[i][j];
    rec(i+1, mask^(1<<i), v, cost + c[i]);
    fr(j, m) v[j] -= a[i][j];
}

void solve(){
    cin>>n>>m>>x;
    int z;
    a.resize(n);
    c.resize(n);
    fr(i, n){
        cin>>c[i];
        fr(j, m){
            cin>>z;
            a[i].push_back(z);
        }
    }

    vector<int> v(m, 0);
    rec(0, 0, v, 0);

    if(ans == inf){
        cout<<-1;
    } else cout<<ans;
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

