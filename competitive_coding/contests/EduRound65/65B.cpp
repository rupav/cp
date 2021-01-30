#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    vector<int> seq = {4, 8, 15, 16, 23, 42};
    map<int, bool> exist;

    map<int, int> mp;
    map<int, bool> prod;
    for(auto c: seq){
        exist[c] = true;
        mp[c] = -1;
    }

    for(int i=0; i<6; i++){
        for(int j=i+1; j<6; j++){
            prod[seq[i]*seq[j]] = true;
        }
    }


    int x;
    cout<<"? 1 1"<<endl;
    fflush(stdout);
    cin>>x;
    mp[sqrt(x)] = 1;

    cout<<"? 2 2"<<endl;
    fflush(stdout);
    cin>>x;
    mp[sqrt(x)] = 2;

    int y, z;
    cout<<"? 3 4"<<endl;
    fflush(stdout);
    cin>>y;

    cout<<"? 4 5"<<endl;
    fflush(stdout);
    cin>>z;

    int w = y*z;
    /// both y & z will have a common factor!, that will be at pos 4.
    for(auto c: seq){
        if(((exist[y/c])) && ((exist[z/c])) && prod[w/(c*c)] && (z/c != c) && (y/c != c)){
            mp[c] = 4;
            mp[y/c] = 3;
            mp[z/c] = 5;
            break;
        }
    }

    int ans[7] = {-1};
    for(auto it: mp){
        if(mp[it.first] != -1){
            ans[it.second] = it.first;
        } else {
            ans[6] = it.first;
        }
    }

    cout<<"! ";
    rep(i, 1, 6){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}

