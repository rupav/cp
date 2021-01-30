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
    fr(i, n)
        cin>>arr[i];
    sort(arr, arr+n);

    unordered_map<int, int> po;
    unordered_map<int, bool> mp;
    int prev = INT_MAX;
    fr(i, n){
        if(arr[i] != prev){
            prev = arr[i];
            po[arr[i]] = i;  /// first pos. of that element!
            mp[arr[i]] = true;
        }
    }
    int res = 1;
    int st = 0;
    rep(i, 1, n-1){
        if(arr[i] - arr[st]<=5)
            continue;
        else{
            res = max(res, i-st);
            if(arr[i] - arr[i-1]>5){
                st = i;
            } else {
                /// find j.

                /*
                for(int j=1; j<=4; j++){
                    if(po[arr[st]+j]>0 && arr[i] - arr[st]+j] <= 5){
                        st = po[arr[st]+j];
                        break;
                    }
                }
                */

                int j = 5;
                while(j>=1){
                    if(mp[arr[i]-j] && po[arr[i]-j]>st){
                        st = po[arr[i]-j];
                        break;
                    }
                    j--;
                }
            }
        }
    }
    res = max(res, n-st);
    cout<<res;
    return 0;
}
