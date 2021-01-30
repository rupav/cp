#include<bits/stdc++.h>
using namespace std;

#define mp(i, j) make_pair(i, j)
typedef long long ll;
const int LIM = 3e5+5;

const int N = 1e6+1;
ll divs[N+1] = {0ll};
ll a[LIM];

ll bit[LIM];

void update(ll i, ll upd){
    for(; i <= LIM; i += i&(-i)) bit[i] += upd;
}

ll pref(ll i){
    ll sum = 0;
    for(; i > 0; i -= i&(-i)) sum += bit[i];
    return sum;
}

ll query(ll l, ll r){
    /// returns sum from l to r inclusive
    return pref(r) - pref(l-1);
}

void fill_(){
    for(ll i=1; i<=N; i++){
        for(ll j=i; j<=N; j+=i) ++divs[j];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m, l,r, c;
    cin>>n>>m;
    fill_();
    set<ll> s; /// set of indices at which elements are greater than 2

    for(ll i=1; i<=n; i++) {
        cin>>a[i];
        update(i, a[i]);
        if(a[i] > 2) s.insert(i);
    }

    for(ll i=0; i<m; i++){
        cin>>c;
        if(c==1){
            // replace
            cin>>l>>r;
            set<ll>::iterator lt = s.lower_bound(l);
            set<ll>::iterator rt = s.upper_bound(r);
            set<ll>::iterator tit;
            for(auto it = lt; it != rt;){
                ll z = divs[a[*it]];
                update(*it, z - a[*it]);
                a[*it] = z;
                if(z <= 2){
                    tit = it;
                    ++it;
                    s.erase(tit);
                } else ++it;
            }
        } else {
            // sum
            cin>>l>>r;
            cout<<query(l, r)<<endl;
        }
    }
}
