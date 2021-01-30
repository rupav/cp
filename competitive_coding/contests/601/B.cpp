#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void solve(){
    int n, m;
    cin>>n>>m;
    pii c[n];
    int minc = 0;
    for(int i=0; i<n; i++) cin>>c[i].first, c[i].second = i, minc += c[i].first;

    if(m<n || (n==2)){
        cout<<-1;
        cout<<endl;
        return;
    }


    minc *= 2;
    m -= n;

    sort(c, c+n);
    vector<pii> ans;
    for(int i=0; i<n; i++){
        ans.push_back({i, (i+1)%n});
    }
    while(m--){
        ans.push_back({c[0].second, c[1].second});
        minc += c[0].first + c[0].second;
    }

    cout<<minc<<endl;
    for(auto it: ans){
        cout<<it.first+1<<" "<<it.second+1<<endl;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
