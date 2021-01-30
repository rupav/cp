#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 17;
pair<ll, bool> t[4*(1<<N)];

ll operate(ll x, ll y, ll op){
    if(op) return (x | y);
    return (x ^ y);
}

bool build(ll a[], ll node, ll tl, ll tr){
    if(tl == tr) {
        t[node].first = a[tl];
        return t[node].second = true;
    }
    ll tm = (tl + tr)>>1;
    bool op = build(a, 2*node, tl, tm);
    build(a, 2*node+1ll, tm+1, tr);
    t[node].first = operate(t[2*node].first, t[2*node+1].first, op);
    return t[node].second = !op;
    return !op;
}

bool update(ll node, ll tl, ll tr, ll pos, ll new_val){
    if(tl == tr) {
        t[node].first = new_val;
        return t[node].second = true;
    }
    ll tm = (tl + tr)>>1;
    bool op;
    if(pos <= tm){
        op = update(2*node, tl, tm, pos, new_val);
    } else {
        op = update(2*node+1, tm+1, tr, pos, new_val);
    }
    t[node].first = operate(t[2*node].first, t[2*node+1].first, op);
    return t[node].second = !op;
}

pair<ll, bool> query(ll node, ll tl, ll tr, ll l, ll r){
    if(l > r) return {0ll, true};
    if(tl == l && tr == r) return t[node];
    ll tm = (tl + tr)>>1;
    pair<ll, bool> res1 = query(2*node, tl, tm, l, min(r, tm));
    pair<ll, bool> res2 = query(2*node+1, tm+1, tr, max(l, tm+1), r);
    return {operate(res1.first, res2.first, res1.second), !res1.second};
}

int main(){
    ll n, m, pos, new_val;
    cin>>n>>m;
    ll a[(1<<n)];
    for(ll i = 0; i < (1<<n); i++){
        cin>>a[i];
    }
    build(a, 1, 0, (1<<n)-1);
    for(ll i= 0; i < m; i++){
        cin>>pos>>new_val;
        pos--;
        update(1, 0, (1<<n)-1, pos, new_val);
        cout<<query(1, 0, (1<<n)-1, 0, (1<<n)-1).first<<endl;
    }
    return 0;
}
