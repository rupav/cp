#include<bits/stdc++.h>
#define fr(i, n) for(int i=0; i<n; i++)
using namespace std;

struct Process{
    int at;
    int bt;
    int ind;
};

bool compare(Process p1, Process p2){
    return p1.ind > p2.ind;
}

int main(){
    int n;
    cout<<"Enter # of processes"<<endl;
    cin>>n;
    Process proc[n];

    cout<<"Enter arrival time"<<endl;
    fr(i, n){
        cin>>proc[i].at;
        proc[i].ind = i;
    }
    priority_queue<Process, vector<Process>, bool(*)(Process, Process) > pq;
    cout<<"Enter burst time"<<endl;
    fr(i, n){
        cin>>proc[i].bt;
    }
    map<int, vector<Process> > mp;
    fr(i, n){
        mp[proc[i].at].push_back(proc[i]);
    }

    int tq;
    cout<<"Enter time quantum"<<endl;
    cin>>tq;
    cout<<"Implementing Round Robin Scheduling..."<<endl;

    map<int, vector<Process> >::iterator it = mp.begin();
    int time = it->first;
    int i=0;
    while(i < it->second.size()){
        pq.push(it->second[i]);
        i++;
    }
    int count = 0;
    it++;
    int temp = tq;
    while(true){
        if(it!=mp.end() && time == it->first){
            int i=0;
            while(i < it->second.size()){
                pq.push(it->second[i]);
                i++;
            }
            it++;
        }

        if(pq.size()){
            Process current = pq.top();
            pq.pop();
            current.bt max(0, current.bt - tq);
            if(current.bt == 0){
                count++;
                cout<<"Process P"<<current.ind<<" completed at time: "<<time<<endl;
            } else {
                pq.push(current);
            }
        } else {
            time++;
        }
        if(count>=n){
            break;
        }
    }
    return 0;
}
