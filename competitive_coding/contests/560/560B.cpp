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
    sort(arr, arr+n);
    int count = 0;
    fr(i, n){
        if(arr[i] >= count+1){
            count++;
        }
    }
    cout<<count;
    return 0;
}

