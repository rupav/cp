#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 2e9+7;

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

struct nodes{
    ll x;
    ll t;
};

ll solve(){
    ll n;
    cin>>n;
    nodes a[n+1];

    fr(i, n) cin>>a[i].x;
    a[n].x = mod;
    fr(i, n) cin>>a[i].t;
    a[n].t = 0ll;

    ll res = 0ll;

    sort(a, a+n+1);

    ll i = 0ll, j = 0ll, st = 0ll, k = 0ll, fac = 1ll;
    ll edge;
    ll max_;
    ll id_;
    map<ll, bool> marked;
    priority_queue<ll> pq;

    while(i != n){
        j = i+1;
        max_ = a[i].x;
        id_ = i;
        while(a[j].x == a[i].x){
            if(a[j].t > max_){
                max_ = a[j].t;
                id_ = j;
            }
            j++;
        }
        marked[max_] = true;

        /// a[j].x != a[i].x
        if(a[j].x == a[i].x + 1) {
            i = j;
            continue;
        }
        /// need to change st

        /// this is the edge at a[i].x
        edge = a[i].x;
        k = st;
        while(k <= edge){
            if ( !marked[k] ) {
                pq.push( a[k].t );
                res += (edge - a[k].x)*(a[k].t);
            }
            k++;
        }

        k = edge + 1ll;
        fac = 1ll;
        while(!pq.empty() && k < a[j].x){
            /// fill these greedily
            res += pq.top()*fac;
            pq.pop();
        }

        st = a[j].x;
        i = j;

    }

    return res;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        cout<<solve();
    }

    return 0;
}

