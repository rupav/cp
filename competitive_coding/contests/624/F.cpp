#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fr(i, n) for(int i=0; i<n; i++)

const int N = 2e5 + 5;

struct Point{
    int v, x;
    bool operator<(Point p) { return x < p.x; }
};

Point a[N];
ll bit[N][2];  /// 1 count bit and second sum bit

void compress (int n) {

    /// compress velocity into 2e5 + 4 range
    set<int> s;
    fr(i, n) s.insert(a[i].v);
    map<int, int> mp;
    int val = 1;

    for(auto it: s) mp[it] = val++;

    fr(i, n) a[i].v = mp[a[i].v];

}

void update(int i, bool f, int upd){
    for(; i < N; i += i&(-i)) bit[i][f] += 1ll*upd;
}

ll get(int i, bool f) {
    ll sum = 0ll;
    for(; i > 0; i -= i&(-i)) sum += bit[i][f];
    return sum;
}

int main(){
    int n;
    cin>>n;

    fr(i, n) cin>>a[i].x;
    fr(i, n) cin>>a[i].v;

    sort(a, a+n);
    compress(n);

    ll res = 0ll;
    ll cnt, sum;

    fr(i, n){
        cnt = get(a[i].v, false);
        sum = get(a[i].v, true);
        res += (a[i].x)*cnt - sum;
        update(a[i].v, false, 1);
        update(a[i].v, true, a[i].x);
    }

    cout<<res;

    return 0;
}
