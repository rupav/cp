/// O (nlogn approach!) - geeks refer https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
vector<int> a;

int lis(vector<int> a, int n, bool strict){
    /// return length of longest increasing subsequence in the given array in O(nlog(n)) time
    vector<int> en;
    for(int i=0; i<n; i++){
        auto it = (strict) ? lower_bound(en.begin(), en.end(), a[i]) : upper_bound(en.begin(), en.end(), a[i]);
        if(it != en.end()) *it = a[i];
        else en.push_back(a[i]);
    }
    return en.size();
}

int main(){
    int n;
    cin>>n;
    a.resize(n);
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<lis(a, n, false);
}

///e.g. 17   1 8 4 12 2 10 6 14 1 6 5 13 3 11 7 15 15
