#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

ll solve(){
    ll a, m;
    cin>>a>>m;
    ll g = gcdll(a, m);
    m /= g;
    ll n = m;
    // return totient of new m
    vector<ll> primes;
    for(ll i=2; i*i<=n; i++){
        if(m%i == 0){
            primes.push_back(i);
            while(m%i == 0) m /= i;
        }
    }
    if(m != 1) primes.push_back(m);

    ll res = n;
    for(auto it: primes){
        res /= it;
        res *= (it - 1);
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}
