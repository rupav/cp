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


bool solve(){
    int n;
    cin>>n;
    int a[n];
    fr(i, n) cin>>a[i];
    int par[2] = {0};
    sort(a, a+ n);
    bool f = false;
    fr(i, n){
        par[a[i]&1]++;
        if(i > 0 && a[i] == a[i-1] + 1) f = true;
    }

    return (((par[0]&1) && f) || !(par[0]&1));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "YES" : "NO")<<endl;
    }

    return 0;
}

