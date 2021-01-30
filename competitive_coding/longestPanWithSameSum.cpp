#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

ll longestSpan(int *A, int *B, int n){
    int C[n]; // diff array
    fr(i, n) C[i] = B[i] - A[i];
    /// Now we have to find longest subset whose sum is 0, using sum_so_far and map method (since C[i] can be negative!)
    ll sum_so_far = 0;
    map<ll, int> mp;  /// mp.first stores sum, and mp.second stores first index of that sum found.
    ll span = 0;
    ll x = 0;
    fr(i, n){
        sum_so_far += 1ll*C[i];
        if(sum_so_far == x){
            span = max(span, 1ll*(i+1));
        }

        if(mp.find(sum_so_far - x) != mp.end()){
            span = max(span, 1ll*i-mp[sum_so_far - x]);
        } else {
            if(mp.find(sum_so_far) == mp.end())
                mp[sum_so_far] = i;
        }
    }

    return span;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n], B[n];
        fr(i, n) cin>>A[i];
        fr(i, n) cin>>B[i];
        cout<<longestSpan(A, B, n)<<endl;
    }
    return 0;
}

