#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;


int main(){
    int n, m, t[2], k;
    cin>>n>>m>>t[0]>>t[1]>>k;

    int a[n], b[m];
    fr(i, n){
        cin>>a[i];
        a[i] += t[0];
    }
    fr(i, m) cin>>b[i];

    if(k >= min(m, n)){
        cout<<-1;
        return 0;
    }

    int ans = 0;
    int next[n] = {0};
    /// cancelling x flights from A to B at a time,
    for(int x=0; x<=k; x++){
        next[x] = lower_bound(b, b+m, a[x]) - b;
        /// cancelling k-x flights from B to C.
        if(next[x] + k - x >= m){
            cout<<-1;
            return 0;
        }
        ans = max(ans, b[next[x] + (k-x)] + t[1]);
    }

    cout<<ans;

    return 0;
}

