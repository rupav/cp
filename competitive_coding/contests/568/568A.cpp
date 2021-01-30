
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a[3];
    cin>>a[0]>>a[1]>>a[2];
    ll d;
    cin>>d;
    sort(a, a+3);
    ll ans = 0;
    if(a[1] - a[0] < d) ans += d - a[1] + a[0];
    if(a[2] - a[1] < d) ans += d - a[2] + a[1];
    cout<<ans;

    return 0;
}
