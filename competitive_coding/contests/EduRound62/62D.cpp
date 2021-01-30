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
    ll ans = 0;
    int i, j, k;
    i = 1;
    j = 2;
    k = 3;
    while(k<=n){
        ans += (ll) j*k;
        j=k;
        k+=1;
    }
    cout<<ans;
    return 0;
}

