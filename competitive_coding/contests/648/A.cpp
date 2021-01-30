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


bool solve(){
    int n, m, x;
    cin>>n>>m;
    vector<bool> rows(n + 1, true), cols(m + 1, true);
    rep(i, 1, n){
        rep(j, 1, m){
            cin>>x;
            if(x) {
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }

    int v[2] = {0};
    rep(i, 1, n) v[0] += rows[i];
    rep(i, 1, m) v[1] += cols[i];

    return (min(v[0], v[1])&1);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "Ashish": "Vivek")<<endl;
    }

    return 0;
}

