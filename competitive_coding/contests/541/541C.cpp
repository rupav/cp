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
    ll arr[n];
    ll res[n];
    priority_queue<ll> maxP;
    priority_queue<ll, vector<ll>, greater<ll>> minP;
    fr(i, n){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    fr(i, n){
        if(i&1) maxP.push(arr[i]);
        else minP.push(arr[i]);
    }

    while(minP.size()){
        cout<<minP.top()<<" ";
        minP.pop();
    }

    while(maxP.size()){
        cout<<maxP.top()<<" ";
        maxP.pop();
    }

    fr(i, n){
        // cout<<res[i]<<" ";
    }

    return 0;
}
