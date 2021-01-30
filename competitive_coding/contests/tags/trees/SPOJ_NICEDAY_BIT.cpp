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
int bit[LIM];
int n;

int getMin(int i){
    /// returns min from 0 to ind
    int min_ = INT_MAX;
    for(; i>0; i -= i&(-i)) min_ = min(min_, bit[i]);
    return min_;
}

void update(int i, int val){
    for(; i <=n; i+=i&(-i)) bit[i] = min(val, bit[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        rep(i, 0, n) bit[i] = INT_MAX;
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
        for(auto it: a){
            int min_ = getMin(it.second.first-1);
            if(it.second.second < min_) ans++;
            update(it.second.first, it.second.second);
        }

        cout<<ans<<endl;
    }
    return 0;
}

