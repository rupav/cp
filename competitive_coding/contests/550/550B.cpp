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
    priority_queue<int> pq[2];
    fr(i, n){
        cin>>arr[i];
        pq[(arr[i]&1)].push(arr[i]);
    }
    bool flag = true;
    int l = pq[0].size();
    int m = pq[1].size();
    ll res = 0;
    if(l>m){
        flag = false;
        while(true){
            pq[flag].pop();
            flag = (flag) ? false : true;
            if(!pq[1].size() || !pq[0].size()){
                pq[flag].pop();
                break;
            }
        }
        while(pq[0].size()){
            res += 1ll*pq[0].top();
            pq[0].pop();
        }
    } else if (m>l) {
        flag = true;
        while(true){
            pq[flag].pop();
            flag = (flag) ? false : true;
            if(!pq[0].size() || !pq[1].size()){
                pq[flag].pop();
                break;
            }
        }
        while(pq[1].size()){
            res += 1ll*pq[1].top();
            pq[1].pop();
        }
    } else {
        cout<<0;
        return 0;
    }
    cout<<res;
    return 0;
}

