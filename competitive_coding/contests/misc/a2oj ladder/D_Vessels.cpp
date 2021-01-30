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
    ll n, c, p, x, k;
    cin>>n;
    ll a[n];
    fr(i, n) cin>>a[i];
    ll res[n] = {0};
    ll m;
    cin>>m;
    ll nxt[n+1];
    fr(i, n) nxt[i] = i+1;
    nxt[n] = n;

    fr(i, m){
        cin>>c;
        c--;
        if(!c){
            cin>>p>>x;
            p--;
            int st = p, mn;
            stack<int> s;
            while(p != n){
                mn = min(a[p], x);
                res[p] += mn;
                a[p] -= mn;
                x -= mn;
                if(!x) break;
                s.push(p);
                p = nxt[p];
            }
            while(s.size()){
                nxt[s.top()] = p;
                s.pop();
            }
        } else {
            cin>>k;
            k--;
            cout<<res[k]<<endl;
        }
    }

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

