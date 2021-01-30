#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;

int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    fr(i, n) cin>>a[i];
    int d;
    int ans = 0;
    rep(i, 1, n-1){
        d = k - (a[i] + a[i-1]);
        if(d > 0){
            a[i] += d;
            ans += d;
        }

    }
    cout<<ans<<endl;
    fr(i, n) cout<<a[i]<<" ";
    return 0;
}
