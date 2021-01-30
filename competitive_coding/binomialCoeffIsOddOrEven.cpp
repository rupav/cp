#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

/// using Lucas Theorem, with prime, p = 2
int isBinomialCoeffEven(int m, int n){
    int k = sizeof(int)*8;
    for(int i=0; i<k; i++){
        if((n&1) > (m&1))
            return 1;  /// even
        n = n>>1;
        m = m>>1;
    }
    return 0;
}

int main(){
    int m, n;
    cin>>m>>n;
    cout<<isBinomialCoeffEven(m, n)<<endl;
    return 0;
}

