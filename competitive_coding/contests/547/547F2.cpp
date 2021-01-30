/// same as F1, covering hard constraints as well...
#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n;
    cin>>n;
    int arr[n+1] = {0};
    rep(i, 1, n){
        cin>>arr[i];
    }

    map<int, vector<pii>> mp;
    int sum = 0;
    for(int r=1; r<=n; r++){
        /// store smallest blocks first.
        sum = 0;
        for(int l=r; l>0; l--){
            sum += arr[l];
            mp[sum].push_back({l, r});
        }
    }

    set<pii> ans;
    for(auto it: mp){
        sum = it.first;
        set<pii> temp;
        /// now greedily pick up non-overlapping blocks, for a given sum, with r as small as possible!
        int r = 0;
        for(auto block: mp[sum]){
            if(block.first > r){
                temp.insert(block);
                r = block.second;  /// update, for next non-overlapping block!
            }
        }
        if(temp.size() >= ans.size()){
            ans = temp;
        }
    }

    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}


