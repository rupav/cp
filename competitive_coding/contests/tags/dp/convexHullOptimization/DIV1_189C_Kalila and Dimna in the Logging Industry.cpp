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


struct line{
    ll m, c;
    ll val(ll x){
        return m * x + c;
    }
    ll intersectX(line l){
        return (c - l.c) / (l.m - m);
    }
};

struct tree{
    ll a, b;
};

void solve(){
    ll n, x, y, a;
    cin>>n;
    vector<tree> trees(n);
    fr(i, n){
        cin>>x;
        trees[i].a = x;
    }
    fr(i, n){
        cin>>x;
        trees[i].b = x;
    }

    deque<line> dq;

    /// dpi = bj * ai + dpj
    /// m = bj, c = dpj
    /// find min. cost to cut last tree
    /// to minimize, negate both y-intersect and slope, this way question becomes to maximize the negation of dpj.
    /// now slopes are increasing and query points are increasing as well
    /// this means for each query point, we have to delete those lines whose value is less than previous, and these lines, has lesser slope than previous as well.


    dq.push_front({-trees[0].b, 0});
    ll best = 0ll;
    rep(i, 1, n - 1){
        x = trees[i].a;

        while(dq.size() >= 2 && dq.back().val(x) <= dq[dq.size() - 2].val(x))
            dq.pop_back();

        best = -dq.back().val(x);
        line l = {-trees[i].b, -best};

        /// maintain hull
        while(dq.size() >= 2 && dq.front().intersectX(l) <= dq[1].intersectX(dq.front()))
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


