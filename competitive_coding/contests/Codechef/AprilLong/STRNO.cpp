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

ll cnt(ll x){
    ll res = 0ll;
    ll lim = sqrt(x);
    rep(i, 2, lim){
        while(x%i == 0){
            x /= i;
            res++;
        }
    }
    if(x >= 2) res++;
    return res;
}

bool solve(){
    ll x, k;
    cin>>x>>k;
    return cnt(x) >= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

