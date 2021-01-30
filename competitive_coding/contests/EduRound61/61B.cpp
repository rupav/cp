#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, m;
    cin>>n;
    int arr[n];
    ll sum = 0;
    fr(i, n){
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr, arr + n);
    cin>>m;
    int c[m];
    fr(i, m){
        cin>>c[i];
        cout<<sum - arr[n-c[i]]<<endl;
    }
    return 0;
}

