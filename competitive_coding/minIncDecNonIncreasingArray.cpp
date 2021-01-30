#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

/// take example to undesrstand the approach - [3, 1, 5, 2]; [3, 1, 5, 5, 5]; [3, 1, 5, 1, 1, 1]
ll minIncrementDecrementToMakeArrayNonIncreasing(int *arr, int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum = 0;
    fr(i, n){
        if(!pq.empty() && pq.top() < arr[i]){
            sum += arr[i] - pq.top();
            pq.pop();
            pq.push(arr[i]);  /// last 2 statements explains, that min element has been scaled up, so pop it, and then push in pq, the scaled up min., and then out of loop, push arr[i]!
        }
        pq.push(arr[i]);
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    fr(i, n)
        cin>>arr[i];
    cout<<minIncrementDecrementToMakeArrayNonIncreasing(arr, n)<<endl;
    return 0;
}
