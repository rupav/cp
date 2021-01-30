/// https://codeforces.com/blog/entry/62690 - 1. Hills count of triplets such that x[i] < x[j] > x[k], i<j<k
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fr(i, n) for(int i=0; i<n; i++)
const int N = 1e5 +5;
int a[N];

void compress(int n){
    set<int> s;
    fr(i, n){
        s.insert(a[i]);
    }
    int val = 1;
    map<int, int> mp;
    for(auto it: s) mp[it] = val++;
    fr(i, n) a[i] = mp[a[i]];
}

ll bit[N];

void update(int i, int upd){
    for(; i < N; i += i&(-i)) bit[i] += 1ll*upd;
}

ll get(int i) {
    ll sum = 0;
    for(; i > 0; i -= i&(-i)) sum += bit[i];
    return sum;
}

int main(){
    int n;
    cin>>n;
    fr(i, n) cin>>a[i];

    /// nlogn solution, for each element find no. of elements lower than it, both to the right and left of it, either using multiset or bit
    /// first compress, and assure each element is >=1
    /// compress
    compress(n);

    int l[n] = {0};
    fr(i, n){
        l[i] = get(a[i] - 1);
        update(a[i], 1);
    }

    ll res = 0ll;

    fr(i, n) bit[i] = 0;
    for(int i=n-1; i>=0; i--){
        res += get(a[i] - 1) * 1ll * l[i];
        update(a[i], 1);
    }

    cout<<res;
    return 0;
}
