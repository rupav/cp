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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    /// rearrangement inequality question
    ll m, n;
    cin>>n>>m;
    ll a[n];
    fr(i, n) cin>>a[i];

    sort(a, a+n);
    ll b[m];
    rep(i, 0, m-1) b[i] = 0ll;

    fr(i, n){
        b[i%m] += a[i];
    }

    stack<ll> ans;

    ll pen = 0ll;
    ll day = 1;
    ll cnt = 0;
    for(int i=n-1; i>=0; i--){
        pen += day*a[i];
        cnt++;
        if(cnt >= m){
            day++;
            cnt = 0;
        }
    }
    ans.push(pen);

    for(int i=n-1; i>0; i--){
        int id = i%m;
        pen -= b[id];
        b[id] -= a[i];
        ans.push(pen);
    }

    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }

    return 0;
}

