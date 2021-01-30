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


void solve(){
    int n;
    cin>>n;
    int a[n + 1];
    int pos[n + 1];
    bool rev = false;
    rep(i, 1, n) {
        cin>>a[i];
        pos[a[i]] = i;
    }
    if(pos[1] > pos[n]){
        rev = true;
        reverse(a + 1, a + n + 1);
        rep(i, 1, n) pos[a[i]] = i;
    }


    vector<int> res;

    /// pos[n] > pos[1]
    /// n, 2, n - 2, 3
    vector<int> v;
    v.push_back(n);
    int nxt = 2;
    int sm = 2, lg = n - 1;
    int mx = pos[n];
    bool f = true;
    while(mx != n){
        if(sm > n) f = false;
        if(lg < 1) f = true;
        if(f){
            /// 2, 3,
            if(pos[sm] > mx){
                mx = pos[sm];
                v.push_back(sm);
                f = false;
                /// find n - nxt
            } sm++;

        } else {
            if(pos[lg] > mx){
                mx = pos[lg];
                v.push_back(lg);
                f = true;
            }
            lg--;
        }
    }

    int sz = v.size();
    repn(i, sz - 1, 0) res.push_back(v[i]);

    /// now for 1, to left
    v.clear();
    v.push_back(1);
    nxt = 1;
    sm = 2, lg = n - 1;
    mx = pos[1];
    f = false;
    while(mx != 1){
        if(sm > n) f = false;
        if(lg < 1) f = true;
        if(f){
            if(pos[sm] < mx){
                mx = pos[sm];
                v.push_back(sm);
                f = false;
            }
            sm++;
        } else {
            if(pos[lg] < mx){
                mx = pos[lg];
                v.push_back(lg);
                f = true;
            } nxt++;    /// find 2 or n - 2 whatever
            lg--;
        }
        if(mx != 1) v.push_back(a[1]);
    }

    for(auto it: v) res.push_back(it);

    if(!rev){
        reverse(res.begin(), res.end());
    }

    cout<<res.size()<<endl;
    for(auto it: res) cout<<it<<" ";
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


