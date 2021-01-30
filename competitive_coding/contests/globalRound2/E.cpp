#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n;
    cin>>n;
    int arr[n];
    ll ans = 0ll;
    fr(i, n){
        cin>>arr[i];
    }
    ll prev = 0ll;
    int temp = 0;
    fr(i, n){
        temp = arr[i]/2;
        ans += min(prev, 1ll*temp);
        arr[i] -= 2ll*min(prev, 1ll*temp);
        prev -= min(prev, 1ll*temp);
        ans += 1ll*(arr[i]/3);
        prev += 1ll*(arr[i]%3);
    }
    cout<<ans;
    return 0;
}

