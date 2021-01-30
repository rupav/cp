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

vector<bool> vis(26);

void dfs(int v, vector<set<int>> &g){
    if(vis[v]) return;
    vis[v] = true;
    cout<<(char)(v+'a');
    for(auto it: g[v]){
        dfs(it, g);
    }
}

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    vector<set<int>> g(26);

    rep(i, 1, n-1){
        g[s[i] - 'a'].insert(s[i-1] - 'a');
        g[s[i-1] - 'a'].insert(s[i] - 'a');
    }


    int src = -1;
    fr(i, 26){
        if(g[i].size() > 2){
            cout<<"NO"<<endl;
            return;
        }
        if(g[i].size() == 1) src = i;
    }
    if(n>1 && src == -1) {
        cout<<"NO"<<endl;
        return;
    }

    src = (src == -1) ? 0 : src;

    cout<<"YES"<<endl;
    vis.assign(26, 0);

    dfs(src, g);

    fr(i, 26){
        if(!vis[i])cout<<(char)(i + 'a');
    }

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

