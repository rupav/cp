/// https://www.youtube.com/watch?v=CWDQJGaN1gY&feature=youtu.be

#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;  /// prime number

int getNext(int i, int n){
    i += i&(-i);
    return i;
}

/// updateBIT is a O(logn) operation
void updateBIT(int n, int *BIT, int i, int update){
    BIT[i] += update;
    int next = getNext(i, n);
    while(next<=n){
        BIT[next] += update;
        next = getNext(next, n);
    }
}

/// constructBIT is a O(n*logn) operation
void constructBIT(int n, int *arr, int *BIT){
    fr(i, n+1) BIT[i] = 0;  /// initialization.
    fr(i, n){
        updateBIT(n, BIT, i+1, arr[i]);
    }
    return;
}

int getParent(int i, int n){
    i -= i&(-i);
    return i;
}

/// getSum is a O(logn) operation
int getSum(int n, int *BIT, int i){
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

int main(){
    int n;
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    cout<<"Enter array elements"<<endl;
    int *arr = new int[n];
    fr(i,n) cin>>arr[i];
    int *BIT = new int[n+1];
    constructBIT(n, arr, BIT);

    cout<<"BIT Tree constructed is"<<endl;
    fr(i, n+1) cout<<BIT[i]<<" ";
    cout<<endl;

    int q;
    cout<<"Enter no. of queries"<<endl;
    cin>>q;
    cout<<"Enter index range x, y where x<y"<<endl;
    int x, y;
    fr(i, q){
        cin>>x>>y;
        cout<<getSum(n, BIT, y+1)-getSum(n, BIT, x)<<endl;
    }
    return 0;
}
