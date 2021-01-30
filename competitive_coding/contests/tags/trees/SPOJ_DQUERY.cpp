#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

const int N = 1e6+1;
const int LIM = 1e6+1;
int bit[LIM] = {0};
int lastVis[LIM] = {0};

void update(int i, int upd){
    for(; i<=LIM; i+=i&(-i)) bit[i] += upd;
}

int query(int i){
    int sum = 0;
    for(; i>0; i-=i&(-i)) sum += bit[i];
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n+1];
    rep(i, 1, n) scanf("%d", &a[i]);
    int q;
    scanf("%d", &q);
    int l, r;
    vector<pair<int, pii>> queries(q);
    vector<int> ans(q);
    fr(i, q){
        scanf("%d%d", &l, &r);
        queries[i].first = r;
        queries[i].second = {l, i};
    }
    sort(queries.begin(), queries.end());

    int st = 1;
    for(auto it: queries){
        r = it.first;
        l = it.second.first;
        rep(i, st, r){
            if(lastVis[a[i]] == 0){
                lastVis[a[i]] = i;
                update(i, 1);
            } else {
                update(lastVis[a[i]], -1);
                lastVis[a[i]] = i;
                update(i, 1);
            }
        }
        int temp = query(r) - query(l-1);
        ans[it.second.second] = temp;
        st = r+1;
    }

    for(auto it: ans) printf("%d\n", it);

    return 0;
}
