#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
int first[N];
int last[N];
int a[N];
map<int, int> f; // freq map

using pii = pair<int, int>;
int main(){
    int n, q;
    cin>>n>>q;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        f[a[i]]++;
        if(!first[a[i]]) first[a[i]] = i;
        last[a[i]] = i;
    }

    vector<int> blocks;  // stores the indices of starting of the resulting block
    int en = 0;
    for(int i=1; i<=n; i++){
        if(i > en){
            blocks.push_back(i);
        }
        en = max(en, last[a[i]]);
    }
    blocks.push_back(n+1);

    int m = blocks.size();
    int cnt = 0, max_ = 0;
    for(int i=1; i<m; i++){
        max_ = 0;
        for(int j=blocks[i-1]; j<blocks[i]; j++){
            max_ = max(max_, f[a[j]]);
        }
        cnt += blocks[i] - blocks[i-1];
        cnt -= max_;
    }

    cout<<cnt;

    return 0;
}
