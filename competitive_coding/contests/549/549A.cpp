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
    int count[2] = {0};
    int val;
    fr(i, n){
        cin>>val;
        arr[i] = val;
        count[val]++;
    }
    fr(i, n){
        val = arr[i];
        count[val]--;
        if(count[val] == 0){
            cout<<i+1;
            return 0;
        }
    }
    return 0;
}

