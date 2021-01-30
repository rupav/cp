#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

ll modularExponentiation(ll x, ll y, ll p = mod){
    if(y==0)
        return 1;
    if(y == 1)
        return x;
    if(y&1){
        /// y is odd, so (x*(x^(y-1)))%p
        return (x*modularExponentiation(x, y-1, p))%p;
    } else {
        /// y is even, so (x^(y/2))^2
        ll c = modularExponentiation(x, y/2, p);
        return (c*c)%p;
    }
}

int main(){
    ll a, b;
    cin>>a>>b;
    cout<<modularExponentiation(a, b)<<endl;
    return 0;
}

