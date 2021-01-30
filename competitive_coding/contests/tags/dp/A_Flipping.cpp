#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][N];
int pref[N], a[N];

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        pref[i] = pref[i-1] + a[i];
    }

    int ans = 0;
    int tot = pref[n];
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            int x = pref[j] - pref[i-1];
            ans = max(ans, tot - x + (j - i + 1 - x));
        }
    }
    cout<<ans;

    return 0;
}
