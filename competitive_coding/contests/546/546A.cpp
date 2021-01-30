#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int main(){
    int n, k;
    cin>>n;
    int arr[2*n+1];
    fr(i, 2*n){
        cin>>arr[i];
    }
    cin>>k;
    int i=0;
    while(arr[i]<k){
        i++;
    }
    cout<<n-(i/2);
    return 0;
}

