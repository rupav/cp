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

ll func(int *arr, int n){
    int lmax, rmax, i, j;
    lmax = rmax = i = 0;
    j = n-1;
    ll rain = 0;
    while(i < j){
        if(arr[i] < arr[j]){
            if(arr[i] > lmax) lmax = arr[i];
            else rain += 1ll*(lmax - arr[i]);  /// its gauranteed to be filled, since on right we have arr[j], which is already taller than lmax!
            i++;
        } else {
            if(arr[j] > rmax) rmax = arr[j];
            else rain += 1ll*(rmax - arr[j]);
            j--;
        }
    }
    return rain;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int arr[n];
    fr(i, n) cin>>arr[i];

    cout<<func(arr, n)<<endl;

    return 0;
}
