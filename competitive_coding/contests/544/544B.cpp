#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    unordered_map<int, int> mp;  /// freq of elements of modulo!
    fr(i, n){
        cin>>arr[i];
        mp[arr[i]%k]++;
    }
    int res = ((mp[0]/2)*2);  /// even
    rep(i, 1, k/2){
        if(k-i == i){
            if(mp[i]>0)
                res += ((mp[i]/2)*2);
        }else if (mp[i]>0 && mp[k-i]>0){
            int t = 2*min(mp[k-i], mp[i]);
            res += t;
        }
    }
    cout<<res;
    return 0;
}

