#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int kadaneMaxSumSubArray(int *arr, int n){
    ll res[n];
    res[0] = arr[0];
    rep(i, 1, n-1){
        res[i] = max(res[i-1]+1ll*arr[i], 1ll*arr[i]);
    }
    ll ans = 0;
    fr(i, n)
        ans = max(ans, res[i]);
    return ans;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    fr(i, n){
        cin>>arr[i];
    }
    cout<<kadaneMaxSumSubArray(arr, n);
    return 0;
}

