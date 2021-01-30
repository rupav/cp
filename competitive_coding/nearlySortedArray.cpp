#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int *arr = new int[n];
    int temp = k;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // initialization
    priority_queue<int, vector<int>, less<int>> items(arr, arr+k+1);

    int *sorted = new int[n];
    int index = 0;
    for(int i=k+1; i<n; i++){
        sorted[index++] = items.top();
        items.pop();
        items.push(arr[i]);
    }
    while(items.size()){
        sorted[index++] = items.top();
        items.pop();
    }
    cout<<"Sorted array is"<<endl;
    for(int i=0; i<n; i++){
        cout<<sorted[i]<<" ";
    }
    return 0;
}
