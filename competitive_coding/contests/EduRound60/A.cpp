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
    ll arr[n];
    ll maxE = -1;
    fr(i, n){
        cin>>arr[i];
        maxE = max(maxE, arr[i]);
    }
    int count = 0;
    int i=0;
    while(i<n){
        if(arr[i] == maxE){
            int j=i+1;
            while(arr[j] == maxE)
                j++;
            count = max(count, j-i);
            i = j;
        } else
            i++;
    }
    cout<<count;
    return 0;
}
