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

bool check(int i, int j, int n){
    /// lower half or upper half
    return j > n - i;
}

void solve(){
    int n, k;
    cin>>n>>k;
    map<int, vector<pii>> mp[2];    /// row <= col, row > col
    rep(i, 1, n){
        rep(j, 1, n){
            mp[check(i, j, n)][i + j].push_back(make_pair(i, j));
        }
    }

    vector<vector<bool>> a(n + 1, vector<bool>(n + 1, false));

    bool f = true;
    map<int, vector<pii>>::iterator it[2] = {mp[0].begin(), mp[1].begin()};
    
    while(it[f] != mp[f].end()){
        for(auto c: it[f]->second){
            if(k >= 1)
                a[c.first][c.second] = 1;
            k--;
        }
        it[f]++;
        f = !f;
    }

    ll mx[2] = {0ll, 0ll}, mn[2] = {(ll)n, (ll)n};
    ll sm = 0ll;
    rep(i, 1, n){
        sm = 0ll;
        rep(j, 1, n){
            sm += a[i][j];
        }
        mx[0] = max(mx[0], sm);
        mn[0] = min(mn[0], sm);
    }

    rep(j, 1, n){
        sm = 0ll;
        rep(i, 1, n){
            sm += a[i][j];
        }
        mx[1] = max(mx[1], sm);
        mn[1] = min(mn[1], sm);
    }


    sm = 0ll;
    fr(i, 2){
        sm += (mx[i] - mn[i]) * (mx[i] - mn[i]);
    }


    cout<<sm<<endl;
    rep(i, 1, n){
        rep(j, 1, n){
            cout<<a[i][j];
        }
        cout<<endl;
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

