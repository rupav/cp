#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    priority_queue<int, vector<int>, greater<int>> pq[n+1];
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        if(a!=b){
            pq[a].push(b);
            pq[b].push(a);
        }

    }

    unordered_map<int, bool> myMap;
    for(int i=1; i<=n; i++)
        myMap[i] = false;

    myMap[1] = true;
    int count = n-1;
    cout<<1<<" ";
    int last = 1;
    while(count--){
        while(myMap[pq[last].top()]){
            int temp = pq[last].top();
            pq[last].pop();
            last = temp;
        }
        cout<<pq[last].top()<<" ";
        myMap[pq[last].top()] = true;
        int temp = pq[last].top();
        pq[last].pop();
        last = temp;
    }

    return 0;
}
