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

struct LINE{
    ll m, c;
    ll val(ll x){
        return m * x + c;
    }
    ll intesectX(LINE l){
        /// l.m * x + l.c = m * x + c =>
        ll x = (c - l.c) / (l.m - m);
        return x;
    }
};

struct RECT{
    ll p, q;    /// x, y
    ll a;

    bool operator<(const RECT &b){
        return p < b.p;
    }

    ll val(){
        return p * q - a;
    }
};


void solve(){
    ll n, x, y, a;
    cin>>n;
    vector<int> ints(n);
    iota(ints.begin(), ints.end(), 0);

    deque<LINE> dq;
    dq.push_front({0, 0});

    auto cmp = [&dq](int idx, int x){
        return dq[idx].intesectX(dq[idx + 1]) < x;
    };

    vector<RECT> rect(n);
    fr(i, n){
        cin>>x>>y>>a;
        rect[i] = {x, y, a};
    }

    sort(rect.begin(), rect.end()); /// without sorting, slopes will not be ordered, and thus insertion will not be possible!


    ll ans = 0ll;
    fr(i, n){
        x = rect[i].q;
        /// query - x is arbitrary (not necessarily increasing/decreasing)
        int idx = *lower_bound(ints.begin(), ints.begin() + dq.size() - 1, x, cmp); /// returns first index of the line for which the intersection of line next to it, is less than x!

        ll dpi = dq[idx].val(x) + rect[i].val();
        ans = max(ans, dpi);

        /// insertion
        LINE l = {-rect[i].p, dpi};
        while(dq.size() >= 2 && dq.front().intesectX(l) >= dq[1].intesectX(dq.front()))
            dq.pop_front();
        dq.push_front(l);
    }

    cout<<ans;
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


