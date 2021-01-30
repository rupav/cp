#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
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

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

ll solve(){
    ll n;
    cin>>n;
    ll a[n+1], b[n+1];
    for(ll i=1; i<=n; i++){
        cin>>a[i]>>b[i];
    }

    ll res = *min_element(a+1ll, a+n+1ll);

    ll d[n + 1] = {0};
    ll sum = 0ll;
    if(a[1] > b[n]) d[1] = a[1] - b[n];
    sum += d[1];

    for(ll i=2; i<=n; i++){
        if(a[i] > b[i-1]){
            d[i] = a[i] - b[i-1];
        }
        sum += d[i];
    }

    if(sum == 0ll) return res;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(ll i=1; i<=n; i++){
        pq.push(sum - d[i] + a[i]);
    }

    return pq.top();

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

