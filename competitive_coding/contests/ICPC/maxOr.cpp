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

vector<pii> arr;

void solve(){
    int n;
    cin>>n;
    v.resize(n);
    int x;
    fr(i, n){
        cin>>x;
        v[i] = {x, i};
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
