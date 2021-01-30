#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    int p[n];
    unordered_map<int, priority_queue<int>> mp;
    fr(i, n){
        cin>>p[i];
    }
    int s[n];
    fr(i, n){
        cin>>s[i];
        mp[s[i]].push(p[i]);
    }
    int id;
    int count = 0;
    fr(i, k){
        cin>>id;
        id--;
        if(mp[s[id]].top() != p[id]){
            count++;
        }
    }
    cout<<count;



    return 0;
}
