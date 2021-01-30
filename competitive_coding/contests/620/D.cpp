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

ll gcdll(ll a, ll b){
    if(!b) return a;
    return gcdll(b, a%b);
}


void solve(){
    int n;
    string s;
    cin>>n>>s;

    /// shortest LIS, reverse '<'
    vector<int> ans(n);
    fr(i, n) ans[i] = n - i;

    int i = 0;
    while(i < n-1){
        if(s[i] == '<'){
            int j = i+1;
            while(j < n-1 && s[j] == '<') j++;
            reverse(ans.begin() + i, ans.begin() + j + 1);
            i = j;
            continue;
        }
        i++;
    }

    for(auto it: ans) cout<<it<<" ";
    cout<<endl;

    /// for longest LIS, reverse '>'
    fr(i, n) ans[i] = i + 1;
    i = 0;
    while(i < n-1){
        if(s[i] == '>'){
            int j = i+1;
            while(j < n-1 && s[j] == '>') j++;
            reverse(ans.begin() + i, ans.begin() + j + 1);
            i = j;
            continue;
        }
        i++;
    }

    for(auto it: ans) cout<<it<<" ";
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

