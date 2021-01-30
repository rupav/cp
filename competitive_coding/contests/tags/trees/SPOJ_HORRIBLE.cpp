/// https://www.youtube.com/watch?v=CWDQJGaN1gY&feature=youtu.be

#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;  /// prime number


class FenwickTree{
    int n;
    vector<ll> BIT;

public:

    FenwickTree(int n){
        this->n = n;
        BIT.assign(n, 0);
    }

    void updateBIT(int n, int i, ll update){
        for(; i<=n; i += i&(-i)) BIT[i] += update;
    }

    void updateBatch(int n, int l, int r, ll update){
        /// updates the prefix sum batch from subarray[l...r] only, used for update range, and point queries, given that original BIT formed is of 0 elements only
        updateBIT(n, l, update);
        updateBIT(n, r+1, -update);
    }

    void constructBIT(int n, int *arr){
        for(int i=0; i<=n; i++) BIT[i] = 0;
        for(int i=0; i<n; i++) updateBIT(n, i+1, arr[i]);
    }

    ll preSum(int n, int i){
        ll sum = 0;
        for(; i>0; i -= i&(-i)) sum += BIT[i];
        return sum;
    }

    ll query(int n, int i){
        /// point query, to know what is A[i]
        return preSum(n, i);
    }
};

int main(){

    int t;
    cin>>t;
    while(t--){
        int n, q, c;
        cin>>n>>q;
        FenwickTree bit1(n+1), bit2(n+1);
        ll l, r, upd;
        while(q--){
            /// update each value of range with same val'v' in O(nlogn) time
            cin>>c;
            if(c == 0){
                cin>>l>>r>>upd;
                bit1.updateBIT(n, l, upd);
                bit1.updateBIT(n, r+1, -upd);
                bit2.updateBIT(n, l, upd*(l-1));
                bit2.updateBIT(n, r+1, -upd*r);
            } else {
                cin>>l>>r;
                cout<<(bit1.query(n, r)*r - bit2.query(n, r)) - (bit1.query(n, l-1)*(l-1) - bit2.query(n, l-1))<<endl;
            }

        }
    }
    return 0;
}

