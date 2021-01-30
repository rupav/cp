#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, l, r, x;
    cin>>n>>m;
    set<int> s;
    for(int i=1; i<=n; i++) s.insert(i);
    vector<int> ans(n+1, 0);

    for(int i=0; i<m; i++){
        cin>>l>>r>>x;
        set<int>::iterator lt = s.lower_bound(l);
        set<int>::iterator rt = s.upper_bound(r);
        for(auto it = lt; it != rt; ++it){
            if(*it != x){
                ans[*it] = x;
            }
        }
        s.erase(lt, rt);
        s.insert(x);
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";

    return 0;
}
