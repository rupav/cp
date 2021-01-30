#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

/// O(n^2) approach
int longestIncreasingSubsequence(int *arr, int n){
    int dp[n];
    int parent[n];
    fr(i, n){
        dp[i] = 1;
        parent[i] = i;
        fr(j, i){
            if(arr[j] <= arr[i]){
                if(dp[j]+1 >= dp[i]){
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                }
            }
        }
    }
    int maxI;
    int lis = 0;
    fr(i, n){
        if(dp[i] > lis){
            lis = dp[i];
            maxI = i;
        }
    }
    stack<int> si;
    while(parent[maxI] != maxI){
        si.push(maxI);
        maxI = parent[maxI];
    }
    si.push(maxI);
    while(!si.empty()){
        // cout<<arr[si.top()]<<" ";
        si.pop();
    }
    // cout<<endl;
    return lis;
}

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

void solve(){
    int n;
    cin>>n;
    a.resize(n);
    fr(i, n) cin>>a[i];
    /// return lis in O(nlogn)

    //cout<<longestIncreasingSubsequence(a, n)<<endl;
    cout<<lis(a, n, false);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

