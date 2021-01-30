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
    rep(i, 1, n){
        cin>>arr[i];
    }
    ll ans = 0;
    int next = 1;
    int i=1;
    int dest = 0;
    while(i<=n){
        dest = max(arr[i], i);
        if(dest == i){
            i++;
            ans++;
            continue;
        }
        while(i <= dest){
            if(arr[i] > dest){
                dest = arr[i];
            }
            i++;
        }
        ans++;
    }
    cout<<ans;
    return 0;
}

