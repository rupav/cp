/// https://codeforces.com/contest/165/problem/E
/// finding if there exists for each element some other element in the array such that their pairwise bitwise AND is 0
/// memory limit error, using these, for dp[][], I need to have some <2.9 bytes data type, instead of 4 byte int

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fr(i, n) for(int i=0; i<n; i++)

int f[1<<22];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];

    fr(i, (1<<22)){
        f[i] = -1;
    }

    fr(i, n){
        cin>>a[i];
        f[a[i]] = a[i];
    }

    fr(mask, (1<<22)){
        fr(i , 22){
            if((mask&(1<<i))){
                if(f[mask] == -1){
                    f[mask] = f[mask^(1<<i)];  /// either 1, or submask value
                } else {
                    /// do nothing, let the mask remains the same
                }
            } else {
                /// do nothing, for this mask
            }
        }
    }

    fr(i, n){
        cout<<f[(1<<22) - 1 - a[i]]<<" ";
    }

    return 0;
}

