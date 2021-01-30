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
    int arr[n+1];
    rep(i, 1, n) cin>>arr[i];
    int ans = 0;
    rep(i, 1, n-1){
        if(arr[i] != arr[n]){
            ans = n-i;
            break;
        }
    }
    for(int i=n; i>1; i--){
        if(arr[i] != arr[1]){
            ans = max(ans, i-1);
            break;
        }
    }
    cout<<ans;
    return 0;
}

