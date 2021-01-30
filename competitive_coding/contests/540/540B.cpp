#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

/// ll prefix[100002];

int main(){
    int n;
    cin>>n;
    ll prefix[n];
    int arr[n];
    int j=0;
    ll sum = 0;
    if(n==1){
        cout<<1;
        return 0;
    }
    fr(i, n){
        cin>>arr[i];
        prefix[i] = (i>1) ? (arr[i] + prefix[i-2]) : arr[i];
        sum += arr[i];
    }

    int lastEven = (n&1) ? n-1 : n-2;
    int lastOdd = (n&1) ? n-2: n-1;
    ll temp = 0;
    ll lastPrefix;
    int count = 0;
    fr(i, n){
        temp = sum - arr[i];
        if(temp%2==0){
            temp /= 2;
            if(i&1){
                if(i==1){
                    lastPrefix = prefix[lastEven] - arr[0];
                } else {
                    lastPrefix = prefix[lastEven] + prefix[i-2] - prefix[i-1];
                }
            } else {
                if(i==0){
                    lastPrefix = prefix[lastOdd];
                } else {
                    lastPrefix = prefix[lastOdd] - prefix[i-1] + prefix[i-2];
                }
            }
            if(lastPrefix == temp)
                count++;
        }

    }
    cout<<count;

    return 0;
}
