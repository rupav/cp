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

/// segment tree to find the kth element
const int N = 3e5 + 5;
int t[4*N]; /// stores no. of 1s in a segment, basically sum


int n, m, k, pos, ind;
int a[N];
pii seq[N];
map<int, vector<pii>> mp;
int res[N];

int bit[N] = {0};
void update(int i, int upd){
    for(; i<N; i += i&(-i)) bit[i] += upd;
}

int get(int i){
    int sum = 0;
    for(; i>0; i -= i&(-i)) sum += bit[i];
    return sum;
}

int find_(int cf){
    /// O(log(n)) approach
    int n = 1<<18;
    int bitmask = n;

    int idx = 0;
    int ans = 0;
    while(bitmask != 0){
        int tIdx = bitmask + idx;  // temporary index
        bitmask >>= 1;  // divide the interval by two
        if (tIdx > n) continue;
        if (bit[tIdx] >= cf) {
                ans = tIdx;
        } else {
            cf -= bit[tIdx];
            idx = tIdx;
        }
    }
    return ans;
}

int bin_search(int cf){
    /// O(log(n)^2) approach
    int l = 1, r = n;
    int ans = 1;
    while(l <= r){
        int m = l + (r - l)/2;
        if(get(m) >= cf) {
            r = m-1;
            ans = m;
        }
        else l = m+1;
    }
    return ans;
}

void solve(){
    cin>>n;
    fr(i, n) {
        cin>>a[i];
        seq[i] = {-a[i], i};
    }
    sort(seq, seq + n);     /// stable sort, with largest amplitude in the beginning
    fr(i, n) seq[i].first = abs(seq[i].first);

    cin>>m;
    fr(i, m){
        cin>>k>>pos;
        mp[k].push_back({pos, i});
    }

    /// start filling the elements, i.e. iterating k from 1 to n,
    rep(len, 1, n){
        update(seq[len-1].second + 1, 1);   /// 1-based indexed fenwick tree

        for(auto el: mp[len]){
            pos = el.first;
            /// finding ind using binary search over bit, prefix sum
            ind = bin_search(pos);
            ind--;

            res[el.second] = a[ind];
        }
    }

    fr(i, m){
        cout<<res[i]<<endl;
    }

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

