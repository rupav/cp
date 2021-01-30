/// primality testing O(k*ln^3n) tme complexity

#include<bits/stdc++.h>
using namespace std;

int modularExp(int x, int y, int p){
    int res = 1;
    x = x%p;
    while(y){
        if(y&1) res = (res*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}

bool isComposite(int n, int d, int r, int a){
    int b = modularExp(a, d, n);
    if(b == 1 || b == n-1) return false;

    for(int i=1; i<r; i++){
        b = (b*b)%n;
        if(b == n-1) return false;
    }

    return true;
}

bool MillerRabin(int n){
    /// return true if prime else false;
    if(n==2 || n==3) return true;
    if(n%2 == 0) return false;
    int r(0), d(n-1);  // n-1 is now even
    while(!(d&1)){
        d = d>>1;
        r++;
    }
    /// now n-1 = d*(2^r)

    for(auto a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(a<n)
        if(isComposite(n, d, r, a)) return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<MillerRabin(n)<<endl;
    }
    return 0;
}

