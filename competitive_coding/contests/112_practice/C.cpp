#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i=0; i<n; i++)
typedef long long ll;

ll f[2*1000010];

int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    int n = s.size();
    memset(f, 0, sizeof(f));
    int arr[n];
    fr(i, n) arr[i] = (int)(s[i] - '0');

    f[0] = 1;
    ll sum = 0ll;
    fr(i, n){
        sum += (arr[i]);
        f[sum]++;
    }

    ll ans = 0;
    fr(i, n){
        if(k == 0){
            /// choose 2 points in each freq, starting point will be next point of 1st, and ending point of the substring will be the 2nd point chosen
            ans += (f[i]*(f[i] - 1))/2;
        } else {
            /// choose one point in this frequ, and choose next in i+k, freq, nC1*mC1
            ans += f[i]*(f[i+k]);
        }
    }

    cout<<ans;

    return 0;
}
