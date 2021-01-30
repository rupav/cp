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
    int a[n+1];
    vector<vector<int>> v(n+1);
    rep(i, 1, n){
        cin>>a[i];
    }
    int from, to;
    rep(i, 1, m){
        cin>>from>>to;
        v[from].push_back(to);
    }
    int ans = 0;
    /// inspecting all suffixes one by one, and putting them in a set
    map<int, bool> mp;
    mp[a[n]] = true;
    int cp = 1;  /// count of pupils which needs to be swapped, for a given prefix.
    for(int i=n-1; i>=1; i--){
        int count = 0;
        // cout<<"a[i]: "<<a[i]<<endl;
        bool flag = true;
        for(auto to: v[a[i]]){
            // cout<<"to: "<<to<<endl;
            if(mp[to] == true){
                count += 1;
                // cout<<"found map true for: "<<to<<endl;
                // cout<<"cp: "<<cp<<endl;
                if(count == cp){
                    /// swap virtually arr[i] && nastya!
                    /// shift nastya to left by 1 virtually, deleting the position of a[i].
                    ans ++;
                    /// no change in cp.
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            mp[a[i]] = true;
            cp++;
        }
    }
    cout<<ans;
    return 0;
}

