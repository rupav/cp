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
    int n, k;
    cin>>n>>k;
    if(n&1 && !(k&1)){
        cout<<"NO"<<endl;
        return;
    }

    int sum = 0;
    if(n&1){
        sum = k - 1;
    } else {
        if(k&1) sum = 2*(k - 1);
        else sum = (k - 1);
    }

    if(sum >= n){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    if(n&1){
        rep(i, 1, k-1) cout<<1<<" ";
        cout<<n - sum;
    } else {
        if(k&1){
            rep(i, 1, k-1) cout<<2<<" ";
            cout<<n - sum;
        } else {
            rep(i, 1, k-1) cout<<1<<" ";
            cout<<n - sum;
        }
    }
    cout<<endl;

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

