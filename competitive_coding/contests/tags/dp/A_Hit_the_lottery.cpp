#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
typedef long long ll;

int main(){
    ll n, a[5] = {1, 5, 10, 20, 100}, ans = 0ll;
    cin>>n;

    for(int i=4; i>=0; i--){
        if(!n) break;
        ans += (n/a[i]);
        n = (n%a[i]);
    }

    cout<<ans;

    return 0;
}
