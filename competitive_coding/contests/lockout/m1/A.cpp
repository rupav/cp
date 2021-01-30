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
#define int ll

struct rect{
    int x1, x2, y1, y2;
    int h, v;   /// length
    int area;
    void in(){
        cin>>x1>>y1>>x2>>y2;
        h = x2 - x1;
        v = y2 - y1;
        area = h * v;
    }
};

void solve(){
    int n;
    cin>>n;
    vector<rect> p(n);
    int mnx = INT_MAX, mxx = -1;
    int mny = INT_MAX, mxy = -1;
    int tot[2] = {0};
    ll area = 0;
    fr(i, n) {
        p[i].in();
        mxx = max(mxx, p[i].x2);
        mnx = min(mnx, p[i].x1);
        mxy = max(mxy, p[i].y2);
        mny = min(mny, p[i].y1);
        area += p[i].area;

        // tot[0] += p[i].h;
        // tot[1] += p[i].v;
    }

    ll h = mxx - mnx;
    ll v = mxy - mny;

    // fr(i, n) watch(p[i].h);

    bool f = false;
    if(h == v && h * v == area) cout<<"YES";
    else cout<<"NO";

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

