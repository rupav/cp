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

const int LIM = 5e5 + 1;
int tree[4*LIM];

void update(int node, int tl, int tr, int pos, int val){
    if(tl > tr) return;
    if(tl == tr){
        tree[node] = val;
    } else {
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(2*node, tl, tm, pos, val);
        } else {
            update(2*node, tm+1, tl, pos, val);
        }
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
}

int getMax(int node, int tl, int tr, int l, int r){
    if(tl > tr) return INT_MIN;
    if(tl == l && tr == r) return tree[node];
    int tm = (tl + tr)/2;
    return max(getMax(2*node, tl, tm, l, min(tm, r)), getMax(2*node+1, tm+1, tr, max(tm+1, tl), tr));
}

void compress(vector<int> &a, int n){
    set<int> s;
    for(auto it: a) s.insert(it);
    int val = 0;
    map<int, int> mp;
    for(auto it: s){
        mp[it] = val++;
    }
    fr(i, n) a[i] = mp[a[i]];
}

int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> z(n);
    fr(i, n) cin>>x[i];
    fr(i, n) cin>>y[i];
    fr(i, n) cin>>z[i];
    compress(x, n);
    compress(y, n);
    compress(z, n);
    vector<pair<int, pii>> a(n);
    fr(i, n) a[i].first = x[i];
    fr(i, n) a[i].second.first = y[i];
    fr(i, n) a[i].second.second = z[i];

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int ans = 0;
    for(auto it: a){
        cout<<it.second.first<<" "<<it.second.second<<endl;
        int max_ = getMax(1, 0, LIM-1, 0, it.second.first - 1);
        if(max_ > it.second.second) ans++;
        update(1, 0, LIM-1, it.second.first, it.second.second);
    }

    cout<<ans;

    return 0;
}
