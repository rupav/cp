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
int tree[4*LIM+1] = {0};

void update(int node, int tl, int tr, int pos, int val){
    if(tl > tr) return;
    if(tl == tr){
        return void(tree[node] = max(val, tree[node]));
    } else {
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(2*node, tl, tm, pos, val);
        } else {
            update(2*node+1, tm+1, tr, pos, val);
        }
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
}

int getMax(int node, int tl, int tr, int l, int r){
    if(l > r) return INT_MIN;
    if(tl == l && tr == r) return tree[node];
    int tm = (tl + tr)/2;
    return max(getMax(2*node, tl, tm, l, min(tm, r)), getMax(2*node+1, tm+1, tr, max(tm+1, l), r));
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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
    // compress(z, n);
    vector<pair<int, pii>> a(n);
    fr(i, n) a[i].first = x[i];
    fr(i, n) a[i].second.first = y[i];
    fr(i, n) a[i].second.second = z[i];


    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int mp[n+1] = {0};
    int ans = 0;
    for(vector<pair<int, pii>>::iterator jit = a.begin(); jit != a.end();){
        // handling duplicates
        auto it = jit;
        while(it != a.end() && it->first == jit->first){
            int max_ = getMax(1, 0, n, it->second.first+1, n);
            if(max_ > it->second.second) ans++;
            it++;
        }
        it = jit;
        int max_;

        while(it != a.end() && it->first == jit->first){
            // max_ = mp[it->second.first];
            if(true || it->second.second > max_){
                /// put at same index, higher value
                update(1, 0, n, it->second.first, it->second.second);
                // mp[it->second.first] = it->second.second;
            }
            it++;
        }
        // mp.clear();

        jit = it;
    }

    cout<<ans;

    return 0;
}
