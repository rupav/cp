/// idea: https://math.stackexchange.com/a/1054206/690943
/// Binary vectors: Galios Field (2): Gaussian Elimination is possible therefore.

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

const int BITS = 32;

int findMSB(int n){
    /// max it can be 31
    for(int i=BITS-1; i>=0; i--){
        if(n&(1<<i)) return i;
    }
    return -1;
}

int maxSubarrayXOR(int A[], int n){
    int *arr = A;  /// just that I like arr instead of A
    vector<int> buckets[BITS];
    // fr(i, BITS) buckets[i].clear();

    /// first put elements of array in respective buckets.
    fr(i, n){
        if(arr[i]){
            buckets[findMSB(arr[i])].push_back(arr[i]);
        }
    }

    int transformed_list[BITS] = {0};  /// after Gaussian Elimination!
    int j = 0;
    for(int i=BITS-1; i>=0; i--){
        if(!buckets[i].empty()){
            int curr = buckets[i].back();
            buckets[i].pop_back();
            transformed_list[j++] = curr;
            for(auto it: buckets[i]){
                int temp = it^curr;
                if(temp) buckets[findMSB(temp)].push_back(temp);
            }
        }
    }

    int ans = 0;
    fr(i, j){
        /// max j can be BITS
        /// now maximizing XOR on transformed list/array.
        /// now transformed_list is gauranteed sorted in decreasing length of MSBs.
        ans = max(transformed_list[i]^ans, ans);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    fr(i, n) cin>>arr[i];
    cout<<maxSubarrayXOR(arr, n);
    return 0;
}
