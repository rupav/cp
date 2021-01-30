/// https://www.youtube.com/watch?v=CWDQJGaN1gY&feature=youtu.be
/// https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/

#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

/// 1-based indexing assumed for all
class FenwickTree{
    int n;
    vector<ll> BIT;
public:
    FenwickTree(int n){
        this->n = n;
        BIT.assign(n+1, 0);
    }

    /// makes the tree from frequencies given
    void constructBIT(int *f, int n){
        for(int i=1; i<=n; i++) updateBIT(i, f[i]);
    }

    /// update a f[i], updating all cumulative frequencies c[j], j>=i and thus updating tree indices as well in O(log(n))
    void updateBIT(int i, ll update){
        for(; i<=n; i += i&(-i)) BIT[i] += update;
    }

    /// update c[l...r] by a value val.
    void updateBatch(int l, int r, ll update){
        updateBIT(l, update);
        updateBIT(r+1, -update);
    }

    /// returns c[1...i] in O(log(n))
    ll query(int i){
        ll sum = 0ll;
        for(; i>0; i -= i&(-i)) sum += BIT[i];
        return sum;
    }

    /// return index, idx for which c[idx] = given cumulative frequency - requires the BIT maximum Index to be a power of 2
    /// requires n to be a power of 2
    /// O(log n)
    int find_(ll cf){
        int bitmask = n;
        cout<<bitmask<<endl;
        int idx = 0;
        while(bitmask != 0){
            int tIdx = bitmask + idx;  // temporary index
            bitmask >>= 1;  // divide the interval by two
            if(tIdx > n) continue;
            if(BIT[tIdx] > cf) continue;
            if(BIT[tIdx] == cf) return tIdx;
            if(BIT[tIdx] < cf){
                cf -= BIT[tIdx];
                idx = tIdx;
            }
        }
        if(cf != 0) return -1;  // no index found upto which cumulative frequ, is equal to cf
        return idx;
    }

    void printBIT(){
        for(int i=1; i<=n; i++) cout<<BIT[i]<<" ";
        cout<<endl;
    }

};

int main(){
    int n;
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    cout<<"Enter array elements"<<endl;
    int *arr = new int[n+1];
    rep(i, 1, n) cin>>arr[i];

    FenwickTree bit1(n), bit2(n);
    bit1.constructBIT(arr, n);
    // bit1.constructBIT(n, arr);
    bit1.printBIT();

    cout<<bit1.find_(6)<<endl;

    /*
    int q;
    cin>>q;
    int l, r, upd;
    while(q--){
        /// update each value of range with same val'v' in O(nlogn) time
        cin>>l>>r>>upd;  /// 0 based indexing, (l, r < n)
        l++;
        r++;

        bit1.updateBIT(n, l, upd);
        bit1.updateBIT(n, r+1, -upd);
        bit2.updateBIT(n, l, upd*(l-1));
        bit2.updateBIT(n, r+1, -upd*r);

    }

    int preSum[n+1] = {0};
    int sum = 0;
    preSum[0] = 0;
    fr(i, n){
        sum += arr[i];
        preSum[i+1] = sum;
    }

    cin>>q;
    while(q--){
        cin>>l>>r;
        l++, r++;
        cout<<(bit1.query(n, r)*r - bit2.query(n, r) + preSum[r]) - (bit1.query(n, l-1)*(l-1) - bit2.query(n, l-1) + preSum[l-1]);
    }
    */

    return 0;
}
