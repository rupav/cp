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


ll solve(){
    string s;
    cin>>s;
    ll n = s.size();
    map<pair<pii, pii>, bool> mp;
    ll cnt = 0;
    ll x(0), y(0);


    for(auto it: s){
        pii st = make_pair(x, y);
        if(it == 'N') y++;
        else if(it == 'S') y--;
        else if(it == 'W') x--;
        else x++;
        if(mp[make_pair(st, make_pair(x, y))] || mp[make_pair(make_pair(x, y), st)]) cnt++;
        else cnt += 5ll;
        mp[make_pair(st, make_pair(x, y))] = 1;
        mp[make_pair(make_pair(x, y), st)] = 1;
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}

