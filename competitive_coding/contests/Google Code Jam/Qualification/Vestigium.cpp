#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    int a[n+1][n+1];
    int trace = 0;
    int cnt[2] = {0};
    rep(i, 1, n){
        map<int, bool> mp;
        bool f = false;
        rep(j, 1, n){
            cin>>a[i][j];
            if(mp[a[i][j]]) f = true;
            mp[a[i][j]] = 1;
            if(i == j) trace += a[i][j];
        }
        if(f) cnt[0]++;
    }

    rep(j, 1, n){
        map<int, bool> mp;
        bool f = false;
        rep(i, 1, n){
            if(mp[a[i][j]]) f = true;
            mp[a[i][j]] = 1;
        }
        if(f) cnt[1]++;
    }

    cout<<trace<<" "<<cnt[0]<<" "<<cnt[1]<<endl;
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
    }

    return 0;
}

