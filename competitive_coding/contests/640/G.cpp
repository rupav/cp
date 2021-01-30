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
    int n;
    cin>>n;
    vector<int> el[2];
    rep(i, 1, n){
        el[i&1].push_back(i);
    }
    reverse(el[1].begin(), el[1].end());
    vector<int> res;

    for(auto it: el[1]) res.push_back(it);

    if(el[0].size() <= 1){
        cout<<-1<<endl;
        return;
    }

    res.push_back(el[0][1]);
    res.push_back(el[0][0]);
    rep(i, 2, el[0].size() - 1) res.push_back(el[0][i]);

    for(auto it: res) cout<<it<<" ";
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

