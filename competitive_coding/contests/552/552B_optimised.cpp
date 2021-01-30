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
    vector<int> v;
    map<int, bool> mp;
    int a;
    fr(i, n){
        cin>>a;
        if(!mp[a])
            v.push_back(a);
        mp[a] = true;
    }
    if(v.size() > 3){
        cout<<-1;
        return 0;
    }
    sort(v.begin(), v.end());
    if(v.size() == 3){
        if(v[1] - v[0] == v[2] - v[1]){
            cout<<v[1] - v[0];
        } else {
            cout<<-1;
        }
    } else if(v.size() == 2){
        int ans = (v[1] - v[0])&1 ? (v[1] - v[0]) : (v[1] - v[0])/2;
        cout<<ans;
    } else {
        cout<<0;
    }
    return 0;
}
