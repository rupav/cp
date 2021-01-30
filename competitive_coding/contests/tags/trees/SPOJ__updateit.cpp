#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

class FenwickTree{
    int n;
    vector<int> BIT;

public:

    FenwickTree(int n){
        this->n = n;
        BIT.resize(n);
        BIT.assign(n, 0);
    }

    void reset(int n){
        BIT.assign(n, 0);
    }

    void updateBIT(int n, int i, int update){
        for(; i<=n; i += i&(-i)) BIT[i] += update;
    }

    void updateBatch(int n, int l, int r, int update){
        /// updates the prefix sum batch from subarray[l...r] only, used for update range, and point queries, given that original BIT formed is of 0 elements only
        updateBIT(n, l, update);
        updateBIT(n, r+1, -update);
    }

    void constructBIT(int n, int *arr){
        for(int i=0; i<=n; i++) BIT[i] = 0;
        for(int i=0; i<n; i++) updateBIT(n, i+1, arr[i]);
    }

    int preSum(int n, int i){
        int sum = 0;
        for(; i>0; i -= i&(-i)) sum += BIT[i];
        return sum;
    }

    int query(int n, int i){
        /// point query, to know what is A[i]
        return preSum(n, i);
    }
};

FenwickTree bit(10005);

void solve(){
    int n, u, q, l, r, upd, i;
    cin>>n>>u;
    bit.reset(n+1);
    while(u--){
        cin>>l>>r>>upd;
        bit.updateBatch(n, l+1, r+1, upd);
    }
    cin>>q;
    while(q--){
        cin>>i;
        cout<<bit.query(n, i+1)<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

