#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

void sort012(int *arr, int n){
    /// arr only have 0, 1, or 2 as elements.
    int l = 0;
    int r = n-1;
    int i=0;
    while(i <= r){
        if(arr[i] == 0){
            /// swap with l index.
            int temp =  arr[i];
            arr[i] = arr[l];
            arr[l] = temp;
            i++;
            l++;
        } else if (arr[i] == 1) {
            i++;
        } else {
            /// swap with r index.
            int temp =  arr[i];
            arr[i] = arr[r];
            arr[r] = temp;
            r--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    fr(i, n){
        cin>>arr[i];
    }
    sort012(arr, n);
    fr(i, n){
        cout<<arr[i]<<" ";
    }
    return 0;
}

