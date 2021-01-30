#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    string t;
    cin>>t;
    int n = t.size();
    int cnt[2] = {0};
    fr(i, n){
        cnt[t[i] == '0']++;
    }
    if(!cnt[0] || !cnt[1]){
        cout<<t<<endl;
        return;
    } else {
        /// period is 2
        string s(2*n, '1');
        fr(i, 2*n) if(i&1) s[i] = '0';
        cout<<s<<endl;
        return;
    }
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

