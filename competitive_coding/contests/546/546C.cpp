#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, m;
    cin>>n>>m;
    map<int, int> mp[n+m+1];
    int val;
    rep(i, 1, n){
        rep(j, 1, m){
            cin>>val;
            mp[i+j][val]++;
        }
    }

    rep(i, 1, n){
        rep(j, 1, m){
            cin>>val;
            if(mp[i+j][val]>0)
                mp[i+j][val]--;
            else{
                cout<<"NO";
                return 0;
            }
        }
    }

    cout<<"YES";
    return 0;
}

