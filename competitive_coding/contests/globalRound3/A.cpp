#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int a[3];
    fr(i, 3) cin>>a[i];
    int temp = min(a[0], a[1]);
    ll ans = 1ll*(a[2]*2) + 1ll*(temp*2);
    a[0] -= temp;
    a[1] -= temp;
    if(a[0]>0 || a[1]>0)
        ans++;
    cout<<ans;
    return 0;
}

