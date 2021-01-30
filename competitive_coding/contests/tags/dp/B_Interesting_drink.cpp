#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
typedef long long ll;

int main(){
    int n;
    cin>>n;
    int a[n];
    fr(i, n) cin>>a[i];
    int q;
    cin>>q;
    sort(a, a+n);
    ll m;
    fr(i, q){
        cin>>m;
        auto z = upper_bound(a, a+n, m) - a;
        cout<<z<<endl;
    }
    return 0;
}
