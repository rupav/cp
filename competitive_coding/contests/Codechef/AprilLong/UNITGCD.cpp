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
    if(n == 1){
        cout<<1<<endl<<1<<" "<<1<<endl;
        return;
    }
    cout<<(n/2)<<endl;
    if(n&1){
        cout<<3<<" "<<1<<" "<<2<<" "<<n<<endl;
        n--;
    } else {
        cout<<2<<" "<<1<<" "<<2<<endl;
    }

    for(int i=3; i<n; i+=2){
        cout<<2<<" "<<i<<" "<<i+1<<"\n";
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

