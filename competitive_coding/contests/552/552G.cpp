#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define maxE 10000005
#define maxN 1000005
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
int f[maxE];
int pos[2][maxE];
int a[maxE], b[maxE];

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    rep(i, 1, n){
        cin>>arr[i];
        f[arr[i]]++;  /// updating the freq. of current element.
        if(!pos[0][arr[i]]) pos[0][arr[i]] = i;
        else if (!pos[1][arr[i]]) pos[1][arr[i]] = i;
    }
    /// G = gcd(A, B); A=RG, B=SG, z = LCM(A, B) = AB/G = GRS... task is to minimize z, by iterating over G from 1 to maxE.

    rep(i, 1, maxE-1){
        /// iterate over all potential GCD
        for(int j=i; j<maxE; j+=i){
            if(!f[j]) continue;
            int m = j/i;  /// either R or S
            if(!a[i]){
                a[i] = m;
                if(f[j] > 1){
                    b[i] = m;
                    break;
                }
            }
            else if(!b[i]) b[i] = m;
            else break;
        }
    }

    ll ans = (ll)1e18;
    int ind[2] = {0};
    rep(i, 1, maxE-1){
        if(!a[i] || !b[i]) continue;
        if( (ll)i*(ll)a[i]*(ll)b[i] < ans ){
            ans = (ll)i*(ll)a[i]*(ll)b[i];
            ind[0] = a[i]*i;
            ind[1] = b[i]*i;
        }
    }

    if(ind[0] == ind[1]){
        cout<<pos[0][ind[0]]<<" "<<pos[1][ind[0]];
    } else {
        cout<<min(pos[0][ind[0]], pos[0][ind[1]])<<" "<<max(pos[0][ind[0]], pos[0][ind[1]]);
    }

    return 0;
}

