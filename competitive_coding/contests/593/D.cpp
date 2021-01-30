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

int gcd(int a, int b){
    if(!b) return a;
    return  gcd(b, a%b);
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

vector<int> constructZFunc(string s){
    int n = s.size();
    vector<int> z(n);
    int l, r;
    l = r = 0;
    z[0] = 0;
    rep(i, 1, n-1){
        z[i] = 0;
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);  /// initialization, req. for linear time approach.
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

int n, m, k;
vector<vector<int>> g;

bool solve(){
    int x, y;
    g.resize(n+1);
    fr(i, k){
        cin>>x>>y;
        g[x].push_back(y);
    }
    rep(i, 1, n){
        sort(g[i].begin(), g[i].end());
    }

    int max_ = m;
    bool flag = false;
    y = g[1].size();

    if(y>0){
        if(g[1][y-1] != max_) return false;
        if(g[1][y-1] - g[1][0] + 1 != y) return false;
        max_ = g[1][0];
    }
    /// downward direction
    rep(i, 2, n-1){
        y = g[i].size();

    }

    rep(i, 2, n){
        y = g[i].size();
        if(y>0){
            // if(g[i][y-1] - g[i][0] + 1 != y) return false; /// not a continuous segment
            if(g[i][y-1] != max_) return false;
            else {
                max_ = g[i][0];
            }
        }
    }  /// now we are at bottom row, in downward direction


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    cout<<solve();


    return 0;
}

