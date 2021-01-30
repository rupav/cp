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

const int N = 4e5 + 5;
ll bit[N];

void update(int i, ll upd){
    for(; i < N; i += i&(-i)) bit[i] = max(bit[i], upd);
}

/// prefix max
ll get(int i){
    ll mx = 0;
    for(; i > 0; i -= i&(-i)) mx = max(mx, bit[i]);
    return mx;
}

struct Q{
    ll l, r, p;
    void in(){
        cin>>l>>r>>p;
    }
    bool operator<(const Q &a){
        return l < a.l;
    }
};

void solve(){
    int n;
    cin>>n;
    vector<Q> projects(n);
    fr(i, n) projects[i].in();
    sort(projects.begin(), projects.end());

    /// coordinate compression
    set<int> s;
    for(auto it: projects) s.insert({it.l, it.r});
    int val = 1;
    map<int, int> mp;
    for(auto it: s) mp[it] = val++;

    for(auto &it: projects){
        it.l = mp[it.l];
        it.r = mp[it.r];
    }

    /// bit maintains dp, dp[i] - max reward gathered if project with starting 'i' is taken as last project in sorted order
    for(auto it: projects){
        update(it.r, get(it.l - 1) + it.p);
    }

    cout<<get(N - 1);
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

