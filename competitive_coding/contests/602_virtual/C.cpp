#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;


void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    string t;   /// target string
    rep(i, 1, k-1){
        t += "()";
    }
    int z = (n - t.size())/2;
    rep(i, 1, z) t += "(";
    rep(i, 1, z) t += ")";

    /// O(n^2) approach, for each s[i] != t[i] find next j>i, such that s[j] = t[i], swap
    vector<pii> ans;

    fr(i, n){
        // break;
        if(t[i] != s[i]){
            int j = i;
            while(s[j] != t[i]) j++;
            /// now s[j] = t[i];, so reverse the whole segment, in between elements will remain same, since are equal!
            s[j] = s[i];
            s[i] = t[i];
            ans.push_back({i, j});
        }
    }

    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it.first + 1<<" "<<it.second + 1<<endl;
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

