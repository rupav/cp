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

const int N = 1e3 + 5;
int vis[N + 1] = {0};
int calc(int n){
    rep(i, 0, n){
        if(!vis[i]){
            return i;
        }
    }    
}

void solve(){
    int n;
    cin>>n;
    int a[n + 1];
    /// final answer to be 0, 1 .... n - 1 made
    rep(i, 0, n) vis[i] = 0;
    fr(i, n){
        cin>>a[i];
        vis[a[i]] += 1;
    }
    vector<int> ops;
    /// first using n steps create a permute of 0 to n - 1
    int mex = calc(n);

    while(mex != n){
        // mex < n
        vis[a[mex]]--;
        vis[mex]++;
        a[mex] = mex;
        ops.push_back(mex);
        mex = calc(n);
    }

    /// now mex is n, now find cycles and print add those indices!
    bool cycvis[n + 1] = {0};
    fr(i, n){
        if(cycvis[i]) continue;
        if(a[i] != i){
            ops.push_back(i);
            int j = a[i];
            while(j != i){
                ops.push_back(j);
                cycvis[j] = 1;
                j = a[j];
            }
            ops.push_back(j);
            cycvis[i] = 1;
        }
    }

    assert(ops.size() <= 2 * n);
    cout<<ops.size()<<endl;
    for(auto it: ops) cout<<it + 1<<" ";
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

