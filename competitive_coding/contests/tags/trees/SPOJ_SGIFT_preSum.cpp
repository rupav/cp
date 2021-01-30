#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define op(i) i&(-i)
using pll = pair<ll, ll>;

const int N = 1e5+5;

int main(){
    int n;
    cin>>n;
    ll a[n+1];
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    ll pref[n+1] = {0};
    for(int i=1; i<=n; i++){
        pref[i] = pref[i-1] + a[i];
    }

    int q;
    ll x, y;
    cin>>q;
    while(q--){
        cin>>x>>y;
        int ind1 = lower_bound(a+1, a+n+1, x) - a;
        ind1--;
        int ind2 = upper_bound(a+1, a+n+1, y) - a;
        ind2--;
        cout<<pref[ind2] - pref[ind1]<<endl;
    }

}
