#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fr(i, n) for(int i=0; i<n; i++)

int main(){
    int q, n;
    cin>>q;
    while(q--){
        cin>>n;
        vector<ll> arr(n);
        fr(i, n) {
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        int x = (upper_bound(arr.begin(), arr.end(), 2048) - arr.begin());
        ll z = accumulate(arr.begin(), arr.begin()+x, 0);
        if(z >= 2048) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
