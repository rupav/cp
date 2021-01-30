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

vector<int> a, k;

int count_le(int x){
    int cnt = 0;
    for(auto i: a) if(i <= x) cnt++;
    for(auto i: k){
        if(i > 0 && i <= x) cnt++;
        if(i < 0 && cnt >= abs(i)) cnt--;
    }
    return cnt;
}

void solve(){
    int n, m;
    cin>>n>>m;
    a.resize(n);
    k.resize(m);
    fr(i, n) cin>>a[i];
    fr(i, m) cin>>k[i];

    if(count_le(2e6 + 5) == 0){
        cout<<0;
        return;
    }

    /// otherwise answer exists
    int lb(1), rb(n+1), mb, ans;
    while(lb <= rb){
        mb = (lb + rb)/2;
        if(count_le(mb)) {
            ans = mb;
            rb = mb - 1;
        } else lb = mb + 1;
    }

    cout<<ans;
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

