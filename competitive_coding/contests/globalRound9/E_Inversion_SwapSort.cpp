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
    int a[n + 1];
    rep(i, 1, n) cin>>a[i];

    set<pii> s;

    vector<pii> res; 
    rep(i, 1, n){
        int j = i + 1;
        while(j <= n){
            if(a[j] < a[i]) s.insert({-a[j], j});
            j++;
        }

        for(auto it: s){
            res.push_back({i, it.second});
        }

        s.clear();
    }

    /// check
    bool f = true;
    for(auto it: res){
        swap(a[it.first], a[it.second]);
    }

    int mn = 0;
    rep(i, 1, n){
        if(a[i] < mn) f = false;
        mn = a[i];
    }

    if(!f) {
        cout<<-1<<endl;
        return;
    }
    cout<<res.size()<<endl;
    for(auto it: res){
        cout<<it.first<<" "<<it.second<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

