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

ll a[2], b[2], p0[2], ps[2], t;
#define LIM 2e16+3
vector<pll> v;

void generate_p(vector<pll> &v){
    ll p[2];
    p[0] = p0[0], p[1] = p0[1];
    while(p[0]<LIM && p[1]<LIM){
        fr(i, 2){
            p[i] = p[i]*a[i] + b[i];
        }
        v.push_back({p[0], p[1]});
    }
}

ll dist(pll p1, pll p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

ll cnt(int st, int n){

    ll time = 0ll;
    ll coins = 0ll;
    pll c = v[st];
    pll prev = {ps[0], ps[1]};
    int x = st+1;

    while(st >= 0){
        time += dist(c, prev);

        if(time > t) {
            return coins;
        }
        coins++;

        prev = c;
        c = v[--st];
    }

    c = v[x];
    while(x < n){
        time += dist(c, prev);

        if(time > t) {
            return coins;
        }
        coins++;
        prev = c;
        c = v[++x];
    }

    return coins;
}

void solve(){
    cin>>p0[0]>>p0[1]>>a[0]>>a[1]>>b[0]>>b[1];
    cin>>ps[0]>>ps[1]>>t;


    v.push_back({p0[0], p0[1]});
    generate_p(v);

    // brute force over all starting points
    ll n = v.size();
    ll ans = 0ll;
    fr(i, n){
        /// v[i] as the starting node
        ans = max(cnt(i, n), ans);
    }

    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll q = 1;
    //  cin>>t;
    while(q--){
        solve();
    }

    return 0;
}

