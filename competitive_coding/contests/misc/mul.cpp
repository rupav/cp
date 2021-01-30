#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int a[N];
map<int, bool> mp;

multiset<int> solve(int n, int k){

    if(mp[n]) {
        multiset<int> s;
        s.insert(n);
        return s;
    }

    vector<multiset<int>> left, right;

    multiset<int> l, r;
    bool f = false;
    for(int i=2; i*i <= n; i++){
        if(n%i == 0){
            f = true;
            l = solve(i, k);
            r = solve(n/i, k);
            left.push_back(l);
            right.push_back(r);
        }
    }

    if(!f) { return multiset<int>(); }

    int m = left.size();
    vector<multiset<int>> merged(m);

    int sz = N;
    for(int i=0; i<m; i++){
        if(!left[i].size() || !right[i].size()) continue;
        merge(left[i].begin(), left[i].end(),
              right[i].begin(), right[i].end(),
              inserter(merged[i], merged[i].end())
              );
        sz = min((int)merged[i].size(), sz);
    }

    if(sz == N) { return multiset<int>(); }  /// no answer found!

    vector<multiset<int>> res;   /// possible results
    for(auto it: merged){
        if((int)it.size() == sz) res.push_back(it);
    }

    m = res.size();

    /// choosing among res, that set which is lexicographically the smallest

    int ind =  0;
    for(int i=1; i<m; i++){
        f = lexicographical_compare (res[i].begin(), res[i].end(), res[ind].begin(), res[ind].end());
        if(f) ind = i;
    }

    return res[ind];

}

int main(){
    int n, k;
    cin>>n>>k;

    for(int i=0; i<k; i++){
        cin>>a[i];
        mp[a[i]] = true;
    }

    multiset<int> s = solve(n, k);

    cout<<1<<" ";
    for(auto it: s) cout<<it<<" ";

    return 0;
}
