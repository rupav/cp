/// Inversion count - count of elements for each i(0 to n-1) such that arr[j] > arr[i] for all j>i.
#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

int getNext(int i, int n){
    i += i&(-i);
    return i;
}

/// updateBIT is a O(logn) operation
void updateBIT(int n, int*BIT, int i, int update){
    BIT[i] += update;
    int next = getNext(i, n);
    while(next<=n){
        BIT[next] += update;
        next = getNext(next ,n);
    }
}

int getParent(int i, int n){
    i -= i&(-i);
    return i;
}

/// getSum is a O(logn) operation
int getSumBIT(int n, int *BIT, int i){
    if(i<0)
        return 0;

    int sum = 0;
    sum += BIT[i];
    int parentIndex = getParent(i, n);
    while(parentIndex>0){
        sum += BIT[parentIndex];
        parentIndex = getParent(parentIndex, n);
    }
    return sum;
}

ll inversionCOunt(int *arr, int n){
    int temp[n];
    fr(i, n) temp[i] = arr[i];
    sort(temp, temp+n);

    ///remove duplicates
    vector<int> v;
    int prev = INT_MIN;
    fr(i, n){
        if(temp[i] != prev)
            v.push_back(temp[i]);
        prev = temp[i];
    }

    /// compress/update arr to range 1, n, maintaining their relative ordering.
    fr(i, n){
        arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
    }

    ll count = 0;
    /// construct BIT in reverse order
    int BIT[n+1] = {0};  // initialize
    for(int i=n-1; i>=0; i--){
        count += 1ll*getSumBIT(n, BIT, arr[i] - 1);
        /// update BIT, by freq of 1 of arr[i]
        updateBIT(n, BIT, arr[i], 1);
    }

    return count;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    fr(i, n) cin>>arr[i];
    cout<<inversionCOunt(arr, n)<<endl;
    return 0;
}

