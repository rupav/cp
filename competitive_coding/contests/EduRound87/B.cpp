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
    string s;
    cin>>s;
    int n = s.size();
    vector<pii> a;
    int i = 0;
    while(i < n){
        int j  = i+1;
        while(j < n && s[j] == s[i]) j++;
        a.push_back({s[i] - '0', j - i});
        i = j;
    }

    int ans = n + 1;
    int m = a.size();

    rep(i, 1, m-2){
        /// consider this as middle element
        if(a[i-1].first != a[i+1].first && a[i].first != a[i-1].first && a[i].first != a[i+1].first){
            ans = min(ans, 2 + a[i].second);
        }
    }

    if(ans == n+1) cout<<0;
    else cout<<ans;

    cout<<endl;
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

