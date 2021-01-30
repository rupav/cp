#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, h;
    cin>>n>>h;
    int arr[n];
    priority_queue<int> pq;
    priority_queue<int> pq_copy;
    ll temp = 0ll;
    fr(i, n){
        cin>>arr[i];
        pq.push(arr[i]);
        /// check if possible now.
        temp = 0ll;
        pq_copy = pq;
        while(pq_copy.size()){
            temp += 1ll*pq_copy.top();
            pq_copy.pop();
            if(temp > 1ll*h){
                cout<<i;
                return 0;
            }
            if(pq_copy.size())
                pq_copy.pop();
        }
    }
    cout<<n;
    return 0;
}

