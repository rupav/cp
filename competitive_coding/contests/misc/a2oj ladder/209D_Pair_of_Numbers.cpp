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

void solve(){
    int n;
    cin>>n;
    int a[n+1], l[n+1], r[n+1];
    rep(i, 1, n) cin>>a[i];
    l[1] = r[n] = 1;
    r[n+1] = n;

    stack<int> s;
    s.push(1);
    rep(i, 2, n){
        l[i] = 1;
        if(a[i-1]%a[i] == 0){
            while(s.size() && (a[s.top()]%a[i] == 0)){
                l[i] += l[s.top()];
                s.pop();
            }
        }
        s.push(i);
    }

    while(s.size()) {s.pop();}

    s.push(n);
    repn(i, n-1, 1){
        r[i] = 1;
        if(a[i+1]%a[i] == 0){
            while(s.size() && (a[s.top()]%a[i] == 0)){
                r[i] += r[s.top()];
                s.pop();
            }
        }
        s.push(i);
    }

    int val[n+1] = {0};
    rep(i, 1, n) val[i] = l[i] + r[i] - 1;
    int max_ = *max_element(val + 1, val + n + 1);
    set<int> res;
    rep(i, 1, n) {
        if(val[i] == max_){
            res.insert(i - l[i] + 1);
        }
    }

    cout<<res.size()<<" "<<max_ - 1<<endl;
    for(auto it: res) cout<<it<<" ";
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

