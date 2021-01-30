#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int con(char c){
    if(c == '?') return 26;
    return (int)(c - 'a');
}

char decon(int n){
    return (char)('a' + n);
}

int main(){
    int n;
    cin>>n;
    string l, r;
    cin>>l>>r;

    int arr[27] = {0};
    map<char, vector<int>> mp;
    int k = 1;
    for(auto c: l){
        arr[con(c)]++;
        mp[c].push_back(k++);
    }

    set<pii> ans;
    k = 1;
    vector<int> qv; /// store indices of '?' of 'r' string.
    vector<int> uv;  /// unused indices of 'r' string that are anot having '?'
    for(auto c: r){
        if(c != '?'){
            if(arr[con(c)]){
                arr[con(c)]--;
                ans.insert(make_pair(mp[c].back(), k));
                mp[c].pop_back();
            } else {
                uv.push_back(k);
            }
        } else {
            qv.push_back(k);
        }
        k++;
    }

    fr(i, 26){
        while(!qv.empty() && arr[i]){
            arr[i]--;
            ans.insert(make_pair(mp[decon(i)].back(), qv.back()));
            mp[decon(i)].pop_back();
            qv.pop_back();
        }
    }

    k = min(mp['?'].size(), uv.size());
    while(k--){
        ans.insert(make_pair(mp['?'].back(), uv.back()));
        uv.pop_back();
        mp['?'].pop_back();
    }

    /// now combine, both '?' from l and r;
    k = min(mp['?'].size(), qv.size());
    while(k--){
        ans.insert(make_pair(mp['?'].back(), qv.back()));
        mp['?'].pop_back();
        qv.pop_back();
    }

    /// print
    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}


