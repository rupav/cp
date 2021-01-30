#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        maxHeap.push(arr[i]);
        minHeap.push(arr[i]);
    }
    unsigned long long sum = 0;
    for(int i=0; i<n/2; i++){
        sum += (minHeap.top()+maxHeap.top())*(minHeap.top()+maxHeap.top());
        minHeap.pop();
        maxHeap.pop();
    }
    cout<<sum<<endl;

    return 0;
}
