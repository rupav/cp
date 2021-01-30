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


void solve(){
    int n;
    cin>>n;
    int a[n+1];
    a[0] = 0;
    rep(i, 1, n) cin>>a[i];
    int l(1), r(1);

    /// find pivot i, s.t., a[i-1] < a[i] > a[i+1]

    set<int> p;
    rep(i, 1, n-1){
        if(a[i] > a[i-1] && a[i] > a[i+1]) p.insert(i);
    }

    int piv = (p.size()) ? *p.begin() : 1;

    /// reverse first downhill slop elements
    int i(piv + 1);

    while(i <= n && a[i] < a[i-1]) i++;
    i--;
    pii ans = {piv, i};

    int j(i);
    i = piv;
    while(i < j){
        swap(a[i++], a[j--]);
    }

    /// check
    bool f = true;
    rep(i, 1, n){
        if(a[i] < a[i-1]) f = false;
    }

    if(f) {
        cout<<"yes"<<endl;
        cout<<ans.first<<" "<<ans.second<<endl;
    } else cout<<"no"<<endl;

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

