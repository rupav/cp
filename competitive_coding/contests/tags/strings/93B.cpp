#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

int main(){
    string s;
    cin>>s;
    vector<int> z = constructZFunc(s);
    int maxZ = 0;
    int n = s.size();
    /*
    for(auto i: z)
        cout<<i<<" ";
    cout<<endl;
    */
    fr(i, n){
        if(z[i]+i == n && maxZ >= n-i){
            /// second condition is to check if we already found such prefix before ith index!
            cout<<s.substr(0, z[i]);
            return 0;
        }
        maxZ = max(maxZ, z[i]);
    }
    cout<<"Just a legend";
    return 0;
}

