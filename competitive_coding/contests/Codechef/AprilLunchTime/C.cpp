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

struct Q{
    ll l, r, i;

};

bool compare(Q a, Q b){
    return a.l < b.l;
}

const ll inf = numeric_limits<ll>::max();

const int N = 1e6 + 2;
ll bit[N];
ll update(ll i, ll n, ll upd){
    for(; i < n; i += i&(-i)) bit[i] += upd;
}

ll get(ll i){
    ll sm = 0ll;
    for(; i > 0; i -= i&(-i)) sm += bit[i];
    return sm;
}

void solve(){
    ll n, q, l, r, x, y;
    cin>>n>>q;
    ll lmx[n];
    ll rmn[n];
    pll points[n];
    // set<pll> s;

    rep(i, 1, N-1) bit[i] = 0ll;

    fr(i, n){
        cin>>x>>y;
        lmx[i] = (x - y);
        rmn[i] = (x + y);
        points[i] = {lmx[i], i};

        update(rmn[i] + 1, N, 1ll); /// 1-based indexing

        // s.insert({-r, i});
    }

    sort(points, points + n);  /// sort by l

    Q queries[q];
    fr(i, q){
        cin>>l>>r;
        queries[i].l = l;
        queries[i].r = r;
        queries[i].i = i;
    }

    sort(queries, queries + q, compare);
    ll ans[n] = {0};

    ll st = 0;
    fr(i, q){
        l = queries[i].l;
        r = queries[i].r;


        /// delete all segments from bit, which have lmx less than l
        while(st < n && points[st].first < l){
            // s.erase({rmn[points[st].second], points[st].second});

            update(rmn[points[st].second] + 1, N, -1); /// erase from bit
            st++;
        }

        /// now points[st] >= l;
        /// find count of segments whose rmn <= r
        ans[queries[i].i] = get(r + 1ll);
    }

    fr(i, q) cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

