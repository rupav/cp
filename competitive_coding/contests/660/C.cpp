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


void solve(){
    int n;
    cin>>n;
    int z = n - 30;
    if (n <= 30){
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        int z = n - 30;
        if(z == 14){
            cout<<"6 10 15 13"<<endl;
        } else if (z == 10){
            cout<<"6 14 15 5"<<endl;
        } else if (z == 6) {
            cout<<"5 6 10 15"<<endl;
        } else
            cout<<"6 10 14 "<<n - 30<<endl;
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

