#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

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
        cout<<arr[si.top()]<<" ";
        si.pop();
    }
    cout<<endl;
    return lis;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    fr(i, n){
        cin>>arr[i];
    }
    cout<<longestIncreasingSubsequence(arr, n)<<endl;
    return 0;
}

