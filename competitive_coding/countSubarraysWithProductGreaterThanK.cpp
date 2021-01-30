#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

ll countProductLesserK(int *arr, int n, ll k){
    ll count = 0;
    int si = -1;
    ll P = 0;  // product so far.
    fr(i, n){
        if(si == -1){
            if(arr[i] < k){
                si = i; /// initialization
                P = 1ll*arr[i];
                count++;
            }
        } else {
            if(1ll*arr[i]*P < k){
                count += (i-si+1);
                P *= 1ll*arr[i];
            } else {
                if(arr[i] >= k){
                    si = i+1;
                    P = 1;
                    count += 0;
                } else {
                    P /= arr[si];
                    rep(j, si+1, i){
                        if(1ll*arr[i]*P < k){
                            /// update si;
                            si = j;
                            count += (i-si+1);
                            P *= 1ll*arr[i];
                            break;
                        } else {
                            P /= arr[j];
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main(){
    int t, n;
    ll k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int arr[n];
        fr(i, n)
            cin>>arr[i];
        cout<<countProductLesserK(arr, n, k)<<endl;
    }
    return 0;
}

