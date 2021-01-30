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


bool solve(){
    ll n, m;
    cin>>n>>m;
    ll max_ = m;
    ll min_ = m;

    ll st = 0ll;

    ll t, l, r, d;
    bool f = true;

    for(ll i = 0ll; i < n; i++) {
        cin>>t>>l>>r;
        d = t - st;

        min_ -= d;
        max_ += d;

        min_ = max(min_, l);
        max_ = min(max_, r);

        if(min_ > max_) f = false;
        st = t;
    }

    return f;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        cout<<(solve() ? "YES" : "NO")<<endl;
    }

    return 0;
}

