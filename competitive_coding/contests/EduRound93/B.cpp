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
    string s;
    cin>>s;
    // no one will care removing 0, other one can always take the benifit!
    int n = s.size();
    int i = 0, j = 0;
    vector<int> v;
    while(i < n){
        if(s[i] == '1'){
            j = i + 1;
            while(j < n && s[j] == '1') j++;
            v.push_back(j - i);
            i = j;
        } else i++;
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    int m = v.size();
    for(int i = 0; i < m; i += 2) ans += v[i];
    cout<<ans<<endl;
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

