#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
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

const int MX = 15000005;
bool p[MX] = {0};
vector<int> spf(MX);    /// stores the smallest prime facto of a number
int pn;                 /// prime no.
vector<int> prime(MX);
int cnt[MX] = {0};

void sieve_linear(int n){
    fill(spf.begin(), spf.begin() + n, 0);
    pn = 0;
    spf[0] = spf[1] = 0;    /// no smallest prime factor!
    for(int i=2; i<n; i++){
        if(!spf[i]) spf[i] = prime[++pn] = i;
        for(int j = 1; i * prime[j] < n; j++){
            spf[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}

/// question reduces to finding largest subsequence whose GCD > 1
void solve(){
    int n;
    cin>>n;
    int a[n], x;
    ll g = 0ll;

    sieve_linear(MX);

    fr(i, n){
        cin>>a[i];
        g = gcdll(g, a[i]);
    }

    fr(i, n) {
        for(int j=a[i]/g; j>1;){
            for(++cnt[x = spf[j]]; spf[j] == x; j/=spf[j]);
        }
    }

    /// now all have gcd = 1
    ll mx = *max_element(cnt, cnt+MX);

    if(mx){
        cout<<n - mx<<endl;
    } else cout<<-1<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

