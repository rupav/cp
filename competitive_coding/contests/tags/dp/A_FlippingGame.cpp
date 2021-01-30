/// https://codeforces.com/problemset/problem/327/A

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
    int count = 0;
    int st = 0;
    int freq = 0;
    fr(i, n){
        cin>>arr[i];
        if(arr[i]){
            freq++;
            count = max(count, i-st);
            st = i+1;
        }
    }
    count = max(count, n-st);
    if(count == 0){
        freq--;
    }
    cout<<count+freq;
    return 0;
}

