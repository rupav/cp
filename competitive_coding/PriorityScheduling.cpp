#include<bits/stdc++.h>
#define fr(i, n) for(int i=0; i<n; i++)
using namespace std;

struct Process{
    int at;
    int bt;
    int pr;
    int ind;
};

bool compare(Process p1, Process p2){
    return p1.pr > p2.pr;
}

int main(){
    int n;
    cout<<"Enter number of Processes"<<endl;
    cin>>n;
    map<int, vector<Process> > mp;
    cout<<"Enter arrival time"<<endl;
    Process *proc = new Process[n];
    fr(i, n){
        cin>>proc[i].at;
        proc[i].ind = i;
        /// mp[proc[i].at].push_back(proc[i]);
    }
    cout<<"Enter burst time"<<endl;
    fr(i, n){
        cin>>proc[i].bt;
    }
    cout<<"Enter their priorities"<<endl;
    fr(i, n){
        cin>>proc[i].pr;
    }

    fr(i, n){
        mp[proc[i].at].push_back(proc[i]);
    }

    map<int, vector<Process> >::iterator it = mp.begin();
    priority_queue<Process, vector<Process>, bool(*)(Process, Process)> pq(compare);
    int i=0;
    while(i < it->second.size()){
        pq.push(it->second[i]);
        i++;
    }
    int time = it->first;
    int count = 0;
    it++;
    while(true){
        if(it!=mp.end() && it->first == time){
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
            current.bt --;
            if(current.bt == 0){
                cout<<"Process P"<<current.ind<<" completed at: "<<time<<endl;
                count++;
            } else {
                pq.push(current);
            }
        }
        time ++;
        if(count>=n){
            break;
        }
    }

    return 0;
}
