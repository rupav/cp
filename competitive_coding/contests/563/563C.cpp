#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int mod = (int)1e5+7;
int ps[100000];
bool prime[100001];


ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}


void SieveOfEratosthenes(int n, int *ans){
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    /// bool prime[n+1];
    for(int i=0; i<=n; i++){
            prime[i] = true;
            ans[i] = 0;
    }

    int val = 1;
    for (int p=2; p <= sqrt(n); p++)
    {
        // If prime[p] is not changed, then it is a prime

        if (prime[p] == true)
        {
            ans[p] = val;
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p){
                if(!ans[i])
                    ans[i] = val;
                prime[i] = false;
            }
            val++;
        }
    }

    for(int i = sqrt(n)+1; i<=n; i++){
        if(prime[i]){
            ans[i] = val;
            val++;
        }
    }



}

int main(){

    int n;
    cin>>n;
    int ans[n];
    SieveOfEratosthenes(n, ans);
    for(int i=2; i<=n; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}

