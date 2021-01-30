#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int findIndex(int a, int d, int t){
    while(true){
        if(((t - a)%d) == 0)
            return t;
        t++;
    }
}

int main(){
    int n, t;
    cin>>n>>t;
    int a, d;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    fr(i, n){
        cin>>a>>d;
        if(t <= a)
            pq.push(make_pair(a, i+1));
        else
            pq.push(make_pair(findIndex(a, d, t), i+1));
    }
    cout<<pq.top().second;
    return 0;
}
