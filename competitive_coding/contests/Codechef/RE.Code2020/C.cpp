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


/// https://www.codechef.com/RC122020/problems/RECNDSTR
bool solve(){
    string s;
    int n;
    cin>>s;
    n = s.size();
    if(n == 1) return true;
    map<char, int> mp[2];
    fr(i, n) mp[i&1][s[i]]++;
    if(mp[0].size() > 1 || mp[1].size() > 1) return false;

    if(n & 1){
        /// all must be equal
        return (mp[0].begin()->first == mp[1].begin()->first);
    } else
        return true;    /// even case
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<(solve() ? "YES" : "NO")<<endl;
    }

    return 0;
}

