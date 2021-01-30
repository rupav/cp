#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int main(){
    int q;
    cin>>q;
    ll a, b, c;
    while(q--){
        cin>>a>>b>>c;
        ll offset = abs(a-b)/2;
        ll temp = c/2;
        if(min(a, b) + temp + offset == max(a, b) + temp - offset){
            cout<<min(a, b) + temp + offset;
        } else {
            if(c&1){
                cout<<max(min(a, b) + temp + offset, max(a, b) + temp - offset);
            } else {
                cout<<min(min(a, b) + temp + offset, max(a, b) + temp - offset);
            }
        }
        cout<<endl;
    }

    return 0;
}

