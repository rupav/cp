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


/// Chef
bool solve(){
    int n;
    cin>>n;
    int sm;
    cin>>sm;
    int z[n];
    vector<int> a[2];
    fr(i, n) cin>>z[i];

    bool x;
    fr(i, n){
        cin>>x;
        a[x].push_back(z[i]);
    }

    fr(i, 2) sort(a[i].begin(), a[i].end());

    if(!a[0].size() || !a[1].size()) return false;

    if(sm + a[0][0] + a[1][0] > 100) return false;
    return true;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "yes" : "no")<<endl;
    }

    return 0;
}
