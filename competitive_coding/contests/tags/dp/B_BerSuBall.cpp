#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, m;
    cin>>n>>m;
    int a1[n], a2[m];
    unordered_map<int, int> mp;  /// freq. map
    fr(i, n){
        cin>>a1[i];
        mp[a1[i]]++;
    }
    int pairs = 0;
    fr(i, m){
        cin>>a2[m];
        if(mp[a2[m]] >= 0)
    }

    return 0;
}


