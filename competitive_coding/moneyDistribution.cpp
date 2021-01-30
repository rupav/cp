/// using stars and bars method!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
const int LIM = 1000005;
ull ifact[LIM];
ull fact[LIM];

ull findModularInverse(ull b, ull exp){
    ull res = 1;
    b = b%MOD;
    while(exp){
        if(exp&1ull){
            res = (res*b*1ull)%MOD;
        }
        exp /= 2ull;
        b = (b*b)%MOD;
    }
    return res%MOD;
}

void fillBinomialCoefficient(int n){
    fact[0] = 1;
    for(int i=1; i<=n; i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    ifact[n] = findModularInverse(fact[n], MOD-2);
    for(int i=n-1; i>=0; i--){
        ifact[i] = (ifact[i+1]*1ull*(i+1))%MOD;
    }
}

ull findBinomialCoefficient(int n, int r){
    return (((fact[n]*findModularInverse(fact[n-r], MOD-2))%MOD)*(findModularInverse(fact[r], MOD-2)%MOD))%MOD;
}

int main(){
        fillBinomialCoefficient(LIM);
        int t;
        cin>>t;
        while(t--) {
            int n, k;
            cin>>n>>k;
            cout<<findBinomialCoefficient(n-1, k-1)<<endl;
        }
	return 0;
}
