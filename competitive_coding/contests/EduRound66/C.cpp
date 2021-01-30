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

    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        ll arr[n];
        fr(i, n) cin>>arr[i];
        /// window size of k+1 elements, choose one with the minimum average of its end points.
        pair<ll, ll> ans = make_pair(mod, -1);

        fr(i, n-k){
            ll dist = arr[i+k] - arr[i];
            ans = min(ans, make_pair(dist, arr[i] + dist/2));
        }
        cout<<ans.second<<endl;
    }

    return 0;
}

