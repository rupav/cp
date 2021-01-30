/// took hint on how to prime factorize n! refer - https://codeforces.com/blog/entry/65136

#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef unsigned long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    ll n;
    ll b;
    cin>>n>>b;

    /// prime factorize b in O(sqrt(b)) time complexity.
    unordered_map<ll, ll> myMap;
    while(b%2==0){
        myMap[2]++;
        b/=2;
    }
    for(ll i=3; i<=sqrt(b); i+=2){
        while(b%i == 0){
            myMap[i]++;
            b/=i;
        }
    }
    if(b>2){
        /// being prime number
        myMap[b]++;
    }
    ll count = 1e18;

    /// Now we have to find prime factorization of n! in terms only p's found in b.
    /// For each p in prime factors of b divide n/p and add floor of it to the power of that p. Divide till n is zero.

    unordered_map<ll, ll>::iterator it = myMap.begin();
    ll t = n;
    while(it != myMap.end()){
        ll cprime = it->first;  /// current prime
        t = n;
        ll cx = 0;
        while(t){
            cx += (t/cprime);
            t/=cprime;
        }
        count = min(count, (ll)(cx/(it->second)));
        if(!count){
            cout<<0;
            return 0;
        }
        it++;
    }
    cout<<count;
    return 0;
}
