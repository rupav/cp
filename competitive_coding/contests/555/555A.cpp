#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

map<ll, bool> mp;

ll rem(ll n){
    while(n%10ll == 0) n/=10ll;
    return n;
}

ll solve(ll n){
    if(mp[n]) return 0;
    mp[n] = true;
    n++;
    /// remove trailing zeros
    n = rem(n);
    return 1ll + solve(n);
}

int main(){
    ll n;
    cin>>n;
    cout<<solve(n);
    return 0;
}

