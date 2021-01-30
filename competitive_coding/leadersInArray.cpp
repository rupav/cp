#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

/// O(n) approach - maintain localMax starting from right side of the array.
void leadersInArray(int *arr, int n){
    int localMax = INT_MIN;
    stack<int> leaders;
    for(int i=n-1; i>=0; i--){
        if(arr[i]>localMax){
            leaders.push(arr[i]);
            localMax = arr[i];
        }
    }
    while(!leaders.empty()){
        cout<<leaders.top()<<" ";
        leaders.pop();
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    fr(i, n){
        cin>>arr[i];
    }
    leadersInArray(arr, n);
    return 0;
}

