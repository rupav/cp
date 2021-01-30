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
    map<int, int> mp;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;

    fr(i, n){
        cin>>arr[i];
        if(mp.find(arr[i]) != mp.end()){
            minHeap.push(arr[i]);
        } else {
            maxHeap.push(arr[i]);
        }
        mp[arr[i]]++;
        if(mp[arr[i]] == 3){
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES"<<endl;
    cout<<minHeap.size()<<endl;
    while(minHeap.size()){
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
    cout<<endl;
    cout<<maxHeap.size()<<endl;
    while(maxHeap.size()){
        cout<<maxHeap.top()<<" ";
        maxHeap.pop();
    }

    return 0;
}

