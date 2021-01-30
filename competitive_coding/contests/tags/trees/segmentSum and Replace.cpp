#include<bits/stdc++.h>
using namespace std;

#define mp(i, j) make_pair(i, j)
typedef long long ll;
const int LIM = 3e5+1;
pair<ll, ll> t[4*LIM];


const int N = 1e6;
ll divs[N+1] = {0ll};
ll a[LIM];

void fill_(){
    for(ll i=1; i<=N; i++){
        for(ll j=i; j<=N; j+=i) ++divs[j];
    }
}

void build(ll node, ll tl, ll tr){
    if(tl == tr) return void(t[node] = mp(a[tl], a[tr]));
    ll tm = (tl + tr)>>1;
    build(2*node, tl, tm);
    build(2*node+1, tm+1, tr);
    t[node].first = t[2*node].first + t[2*node+1].first;
    t[node].second = max(t[2*node].second, t[2*node+1].second);
}

void update(ll node, ll tl, ll tr, ll l, ll r){
    if(l > r) return;
    if(t[node].second <= 2) return;
    if(tl == tr){
        // update
        ll prev = t[node].first;
        t[node] = mp(divs[prev], divs[prev]);
        return;
    }
    ll tm = (tl + tr)>>1;
    if(l <= tm) update(2*node, tl, tm, l, r);
    if(tm+1 <= r) update(2*node+1, tm+1, tr, l, r);
    //  update(2*node, tl, tm, l, min(r, tm));
    //  update(2*node+1, tm+1, tr, max(l, tm+1), r);
    t[node].first = t[2*node].first + t[2*node+1].first;
    t[node].second = max(t[2*node].second, t[2*node+1].second);
}

ll sum(ll node, ll tl, ll tr, ll l, ll r){
    if(l > r) return 0ll;
    if(tl == l && tr == r) return t[node].first;
    ll tm = (tl + tr)>>1;
    return sum(2*node, tl, tm, l, min(r, tm)) + sum(2*node+1, tm+1, tr, max(l, tm+1), r);
}

int main(){
    ll n, m, l, r, c;
    cin>>n>>m;
    fill_();
    for(int i=0; i<n; i++) cin>>a[i];
    build(1, 0, n-1);
    for(int i=0; i<m; i++){
        cin>>c;
        if(c == 1){
            /// replace
            cin>>l>>r;
            l--;
            r--;
            update(1, 0, n-1, l, r);
        } else {
            cin>>l>>r;
            l--;
            r--;
            cout<<sum(1, 0, n-1, l, r)<<endl;
        }
    }
    return 0;
}
