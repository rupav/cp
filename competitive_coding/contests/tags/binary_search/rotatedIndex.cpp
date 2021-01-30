#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    int ans = -1;
    int l=0, r = n-1;
    while(l <= r){
        int m = l + (r - l)/2;
        if(a[m] >= a[0] && a[m] >= a[n-1])
    }

    return 0;
}
