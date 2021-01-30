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

const int LIM = 1e5 + 1;
int tree[4*LIM+1] = {0};

void update(int node, int tl, int tr, int pos, int val){
    if(tl > tr) return;
    if(tl == tr){
        return void(tree[node] = min(val, tree[node]));
    } else {
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(2*node, tl, tm, pos, val);
        } else {
            update(2*node+1, tm+1, tr, pos, val);
        }
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

int getMin(int node, int tl, int tr, int l, int r){
    if(l > r) return INT_MAX;
    if(tl == l && tr == r) return tree[node];
    int tm = (tl + tr)/2;
    return min(getMin(2*node, tl, tm, l, min(tm, r)), getMin(2*node+1, tm+1, tr, max(tm+1, l), r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        rep(i, 0, 4*LIM) tree[i] = INT_MAX;
        vector<int> x(n);
        vector<int> y(n);
        vector<int> z(n);

        fr(i, n) cin>>x[i]>>y[i]>>z[i];

        vector<pair<int, pii>> a(n);
        fr(i, n) a[i].first = x[i];
        fr(i, n) a[i].second.first = y[i];
        fr(i, n) a[i].second.second = z[i];

        sort(a.begin(), a.end());

        int ans = 0;
        for(vector<pair<int, pii>>::iterator jit = a.begin(); jit != a.end();){
            // handling duplicates
            auto it = jit;
            while(it != a.end() && it->first == jit->first){
                int min_ = getMin(1, 0, n, 0, it->second.first-1);
                if(min_ < it->second.second) ans++;
                it++;
            }
            it = jit;

            while(it != a.end() && it->first == jit->first){
                update(1, 0, n, it->second.first, it->second.second);
                it++;
            }

            jit = it;
        }

        cout<<n-ans<<endl;
    }
    return 0;
}
