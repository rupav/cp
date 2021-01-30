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
    int a[n], b[n], c[n];
    fr(i, n){
        cin>>a[i];
    }
    fr(i, n){
        cin>>b[i];
    }
    map<long double, int> mp;
    int res = 0;
    int count = 0;
    fr(i, n){
        if(a[i] == 0 && b[i] == 0)
            count++;
        else if(b[i] == 0){
            mp[0.0]++;
        }else if(a[i] == 0){
            continue;
        } else {
            mp[(long double)((-1.0*b[i])/(1.0*a[i]))]++;
        }
    }
    map<long double, int>::iterator it = mp.begin();
    while(it!=mp.end()){
        res = max(res, it->second);
        it++;
    }
    cout<<res+count;
    return 0;
}

