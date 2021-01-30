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


int solve(){
    string s;
    cin>>s;
    int n = s.size();

    int cnt[2] = {0, 0};
    for(auto it: s) cnt[it == '1']++;

    int mn[2] = {n + 1, n + 1}; /// 000111 && 111000
    int pref[2] = {0};
    int zero = 0, one = 0;
    fr(i, n - 1){
        pref[s[i] == '1']++;
        zero = cnt[0] - pref[0];
        one = cnt[1] - pref[1];
        mn[0] = min(mn[0], pref[1] + zero);
        mn[1] = min(mn[1], pref[0] + one);
    }

    return min({mn[0], mn[1], cnt[0], cnt[1]});
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

