#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, x, y;
    cin>>n>>x>>y;
    ll a[n+1], res[n+1];
    map<ll, bool> mp;
    for(ll i=1; i<=n; i++){
        cin>>a[i];
        mp[a[i]] = true;
    }
    for(ll i=1; i<=n; i++){
        if(mp[x - a[i]]){
            res[i] = 0;
            cout<<a[i]<<" "<<x - a[i]<<endl;
        }
        else if (mp[y - a[i]]){
            res[i] = 1;
            cout<<a[i]<<"-"<<y - a[i]<<endl;
        }
        else {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(ll i=1; i<=n; i++) cout<<res[i]<<" ";
    return 0;
}
