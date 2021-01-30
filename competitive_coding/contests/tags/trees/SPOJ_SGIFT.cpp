#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define op(i) i&(-i)
using pll = pair<ll, ll>;

const int N = 1e5+5;
ll bit[N];
int n;

void update(int i, ll upd){
    for(; i<=n; i+=op(i)) bit[i] += upd;
}

ll query(int i){
    ll sum = 0;
    for(; i>0; i-=op(i)) sum += bit[i];
    return sum;
}

int main(){
    int q;
    cin>>n;
    vector<ll> a(n);
    map<ll, bool> mp;
    set<ll> s;
    for(int i=0; i<n; i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    cin>>q;
    vector<pll> v(q);
    for(int i=0; i<q; i++) {
        cin>>v[i].first>>v[i].second;
        s.insert(v[i].first);
        s.insert(v[i].second);
    }

    map<ll, int> tmp;

    int val = 1;
    for(auto it: s){
        tmp[it] = val++;
    }

    for(auto it = a.begin(); it != a.end(); it++){
        /// *it = tmp[*it];  /// coordinate compression
        update(tmp[*it], *it);
    }

    for(auto it: v){
        cout<<query(tmp[it.second]) - query(tmp[it.first]-1)<<endl;
    }

    return 0;
}
