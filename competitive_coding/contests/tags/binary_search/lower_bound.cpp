#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    sort(a, a + n);

    int ans = -1;
    int l = 0, r = n - 1;

    while(l <= r){
        int m = l + (r - l)/2;
        if(a[m] >= x) ans = m, r = m - 1;
        else if (a[m] < x) l = m + 1;
    }

    cout<<a[ans];

    return 0;
}
