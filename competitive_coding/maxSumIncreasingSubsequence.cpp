#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

ll maxSumIncreasingSubsequence(int *arr, int n){
    ll dp[n];
    int parent[n];
    fr(i, n){
        dp[i] = arr[i];
        parent[i] = i;
        fr(j, i){
            if(arr[j] <= arr[i]){
                dp[i] = max(dp[j] + 1ll*arr[i], dp[i]);
                parent[i] = (dp[i] == dp[j]+1ll*arr[i]) ? j : parent[i];
            }
        }
    }
    ll res = 0;
    int maxI = 0;
    fr(i, n){
        if(dp[i] > res){
            maxI = i;
            res = dp[i];
        }
    }
    stack<int> si;
    while(parent[maxI] != maxI){
        si.push(maxI);
        maxI = parent[maxI];
    }
    si.push(maxI);
    while(!si.empty()){
        cout<<arr[si.top()]<<" ";
        si.pop();
    }
    cout<<endl;
    return res;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    fr(i, n){
        cin>>arr[i];
    }
    cout<<maxSumIncreasingSubsequence(arr, n)<<endl;
    return 0;
}

