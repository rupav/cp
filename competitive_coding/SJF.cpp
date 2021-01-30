#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int in;
    int at;
    int bt;

};

bool myCompare(Node a, Node b){
    return a.bt < b.bt;
}


int main(){
    cout<<"Enter # of Processes"<<endl;
    int n;
    cin>>n;
    Node arr[n];

    cout<<"Enter Burst Time"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i].bt;
        arr[i].in = i+1;
    }

    map<int, vector<Node>> mp;
    cout<<"Enter Arrival Time"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i].at;
        mp[arr[i].at].push_back(arr[i]);
    }

    map<int, vector<Node>>::iterator it;

    priority_queue<Node, vector<Node>, bool (*)(Node, Node)> pq(myCompare);
    it = mp.begin();

    int i = it->second.size();
    while(i--){
        pq.push(it->second[i-1]);
    }

    int time = it->first;
    int count = 0;

    while(!pq.empty() && count!=n){
        Node top = pq.top();
        pq.pop();
        top.bt -= 1;
        time++;
        if(top.bt)
            pq.push(top);
        else{
            cout<<"P"<<top.in<<" CT: "<<time<<endl;
            count++;
        }

        vector<Node> tempVector = mp[time];
        int j = tempVector.size();
        while(j--){
            pq.push(tempVector[j-1]);
            it++;
        }

    }

    return 0;
}
