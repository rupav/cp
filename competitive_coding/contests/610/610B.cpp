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
    ll n, p, k;
    cin>>n>>p>>k;
    vector<ll> a(n);
    fr(i, n) cin>>a[i];
    sort(a.begin(), a.end());
    ll temp = 0ll;
    vector<ll> tSum(n);
    fr(i, n){
        temp += a[i];
        tSum[i] = temp;
    }

    vector<ll> pSum[k];

    ll sum[k] = {0};
    fr(i, n){
        sum[i%k] += a[i];
        pSum[i%k].push_back(sum[i%k]);
    }
    ll l[k] = {0};
    ll r[k] = {0};


    fr(i, k){
        l[i] = upper_bound(pSum[i].begin(), pSum[i].end(), p) - pSum[i].begin();
        ll pos = (l[i]-1)*(k) + i;

        if(l[i] > 0 && (i != k-1)){
            // ll val = p - pSum[i][l[i]-1] + tSum[pos];
            ll val = p - pSum[i][l[i] - 1];
            r[i] = upper_bound(tSum.begin(), tSum.begin()+i, val) - (tSum.begin());
        } else {
            r[i] = 0;
        }
        if((i == k-1) && (l[i] > 0)){
            /// find in next
            ll val = p - pSum[i][l[i]-1] + tSum[pos];
            r[i] = upper_bound(tSum.begin()+pos+1, tSum.end(), val) - (tSum.begin()+pos+1);
        }
    }

    fr(i, k-1){
        l[i] *= k;
        l[i] -= (k-1);
        l[i] = max(0ll, l[i]);
        l[i] += r[i];
    }
    l[k-1] *= k;
    l[k-1] += r[k-1];
    return *max_element(l, l+k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

