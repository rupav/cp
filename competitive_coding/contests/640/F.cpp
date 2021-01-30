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
    int n[3];
    fr(i, 3) cin>>n[i];

    if(!n[1]){
        if(n[0]) rep(i, 1, n[0] + 1) cout<<0;
        else
            rep(i, 1, n[2] + 1) cout<<1;
        cout<<endl;
        return;
    }

    string s;
    if(n[1]&1){
        int k = n[1]/2 + 1;
        rep(i, 1, k) s += "01";
        rep(i, 1, n[0]) cout<<0;
        cout<<s;
        rep(i, 1, n[2]) cout<<1;
        cout<<endl;
        return;
    } else {
        rep(i, 1, (n[1] - 1)/2) cout<<"01";
        cout<<0;
        cout<<1;
        rep(i, 1, n[2]) cout<<1;
        cout<<0;
        rep(i, 1, n[0]) cout<<0;
        cout<<endl;
        return;
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
