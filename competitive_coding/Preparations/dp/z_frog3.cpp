#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;
const ll INF = 1e18L + 5;

vector<ll> h;

struct line{
    ll m, c;
    ll val(ll x){
        return m * x + c;
    }
    ll intesectX(line b){
        /// mx + c = b.mx + b.c
        ll x = (b.c - c) / (m - b.m);
        return x;
    }
};

void solve(){
    ll n, c, x;
    cin>>n>>c;
    h.resize(n);
    fr(i, n) {
        cin>>h[i];
    }

    deque<line> dq;

    auto d = [&](ll x){
        return sq(x);
    };

    dq.push_back({-2ll * h[0], 0ll + d(h[0])});
    ll best = 0ll;
    rep(i, 1, n-1){
        x = h[i];
        /// query
        while(dq.size() >= 2 && dq.back().val(x) >= dq[dq.size() - 2].val(x))
            dq.pop_back();
        ll val = dq.back().val(x);
        best = c + d(h[i]) + val;
        line l = {-2ll * h[i], best + d(h[i])};

        /// insertion
        while(dq.size() >= 2 && l.intesectX(dq.front()) <= dq.front().intesectX(dq[1]))
            dq.pop_front();

        dq.push_front(l);
    }

    cout<<best;
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

