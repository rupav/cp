/// https://codeforces.com/problemset/problem/580/A
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
    int arr[n];
    int res = 0, st = 0;
    int prev = INT_MAX;

    fr(i, n){
        cin>>arr[i];
        if(arr[i] < prev){
            res = max(res, i-st);
            st = i;
        }
        prev = arr[i];
    }
    res = max(res, n-st);
    cout<<res;
    return 0;
}


