#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> cnt;

int main(){
    int n, x, y, z;
    cin>>n;
    v.resize(n);
    cnt.assign(n, 0);
    for(int i=0; i<n; i++){
        cin>>x>>y>>z;
        for(int j=0; j<3; j++){
            cin>>x;
            cnt[x]++;
            v[i].push_back(x);
        }
    }

    for()

    return 0;
}
