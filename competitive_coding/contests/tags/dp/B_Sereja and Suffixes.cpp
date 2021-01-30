#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;

int main(){

    int n, m;
    cin>>n>>m;
    int a[n];
    fr(i, n) cin>>a[i];
    map<int, bool> mp;
    int d = 0;
    for(int i=n-1; i>=0; i--){
        if(mp.find(a[i]) == mp.end()){
            d++;
            mp[a[i]] = true;
        }
        a[i] = d;
    }
    int l;
    fr(i, m){
        cin>>l;
        cout<<a[--l]<<endl;
    }
    return 0;
}
