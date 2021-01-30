#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a) * (a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    int a[n];
    int cnt[2] = {0};
    int odd = 0;
    int diff = 0;
    fr(i, n) {
        cin>>a[i];
        a[i] %= 2;
        cnt[a[i]&1]++;
        odd += (i&1);
        if((i&1) != a[i]) diff++;
    }

    if(odd != cnt[1]){
        cout<<-1<<endl;
        return;
    }

    /// possible
    cout<<(diff/2)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

