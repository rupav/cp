/// can be done offline, after coord compression, and then using BIT.
/// Another approach is segment tree online, with each leaf stores count of 100 salaries.
/// refer - https://codeforces.com/blog/entry/77128
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
#define int ll
ll mod = 1e9+7;

struct Q{
    char c;
    int a, b, k, x;
    void in(){
        cin>>c;
        if(c == '?') cin>>a>>b;
        else cin>>k>>x;
    }
    bool check(){
        return (c == '?');
    }
};

// const int N = 6e5 + 5;
// int bit[N] = {0};
int N;
vector<int> bit;
void update(int i, int upd){
    for(; i < N; i += i&(-i)) bit[i] += upd;
}

int get(int i){
    int sm = 0;
    for(; i > 0; i -= i&(-i)) sm += bit[i];
    return sm;
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n + 1);
    rep(i, 1, n) cin>>a[i];
    vector<Q> q(m);
    fr(i, m) q[i].in();

    /// coodinate compress
    map<int, int> mp;
    vector<int> s;

    rep(i, 1, n) {
        s.push_back(a[i]);
    }
    for(auto it: q){
        if(it.check()) {
            s.push_back(it.a);
            s.push_back(it.b);

        }
        else {
            s.push_back(it.x);
        }
    }
    sort(s.begin(), s.end());

    int val = 1;
    int sz = s.size();
    N = sz + 5;
    bit.resize(N);
    int i = 0;
    while(i < sz){
        mp[s[i]] = val++;
        int j = i + 1;
        while(j < sz && s[j] == s[i]) j++;
        i = j;
    }


    /// now bit on salaries
    rep(i, 1, n) update(mp[a[i]], 1);

    for(auto it: q){
        if(it.check()){
            cout<<get(mp[it.b]) - get(mp[it.a] - 1)<<endl;
        } else {
            update(mp[a[it.k]], -1);
            update(mp[it.x], 1);
        }
    }

}

signed main(){
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
