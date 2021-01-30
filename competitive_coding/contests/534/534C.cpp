#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
int main(){

    string s;
    cin>>s;

    bool v = false;
    bool h = false;

    vector<pii> ans;
    for(auto it: s){
        if(it == '0'){
            if(!v)ans.push_back({1, 4});
            else ans.push_back({3, 4});
            v = !v;
        } else {
            if(!h)ans.push_back({4, 1});
            else ans.push_back({4, 3});
            h = !h;
        }
    }

    for(auto it: ans){
        cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}
