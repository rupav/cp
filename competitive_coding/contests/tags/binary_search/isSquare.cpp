#include<bits/stdc++.h>
using namespace std;

bool solve(int x){
    int l = 0, r = x;

    while(l <= r) {
        int m = l + (r - l)/2;
        if(m * m == x) return true;
        if(m * m > x) r = m - 1;
        else l = m + 1;
    }
    return false;
}

int main(){
    int t, x;
    cin>>t;

    while(t--){
        cin>>x;
        cout<<solve(x);
    }

    return 0;
}
