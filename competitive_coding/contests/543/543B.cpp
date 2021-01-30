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
    int arr[n];
    unordered_map<int, int> mp;
    fr(i, n){
        cin>>arr[i];
    }
    fr(i, n){
        rep(j, i+1, n-1){
            mp[arr[i] + arr[j]] ++;
        }
    }
    unordered_map<int, int>::iterator it = mp.begin();
    int res = 0;
    while(it != mp.end()){
        res = max(res, it->second);
        it ++;
    }
    cout<<res;
    /*
    int maxE = INT_MIN;
    int minE = INT_MAX;
    fr(i, n){
        cin>>arr[i];
        mp[arr[i]] = true;
        maxE = max(maxE, arr[i]);
        minE = min(minE, arr[i]);
    }

    int res = 0;
    rep(i, minE, 2*maxE){
        int count = 0;
        fr(j, n){
            if(i - arr[j] != arr[j] && mp[i - arr[j]]){
                count++;
            }
        }
        res = max(res, count);
    }
    cout<<res/2;
    */

    return 0;
}
