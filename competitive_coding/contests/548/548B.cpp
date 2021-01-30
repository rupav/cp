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
    fr(i, n){
        cin>>arr[i];
    }
    int prev = arr[n-1];
    ll res = arr[n-1];
    for(int i=n-2; i>=0; i--){
        if(arr[i] >= prev){
            arr[i] = prev-1;
            prev = arr[i];
            res += arr[i];
        } else {
            res += arr[i];
            prev = arr[i];
        }
        if(arr[i]<=0){
            res += arr[i];
            break;
        }
    }
    cout<<max(0ll, res);
    return 0;
}

